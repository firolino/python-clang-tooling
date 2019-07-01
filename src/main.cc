#include <string>
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

#include "node-matcher.h"
#include "bound-nodes.h"
#include "wrapper-expose.h"
#include "poly-matcher.h"
#include "simple-expose.h"
#include "tooling/tooling.h"

using namespace std;

template<typename From, typename T, typename... Args>
struct implicitly_convertible_helper_run
{
    using Runner = implicitly_convertible_helper_run<From, Args...>;

    implicitly_convertible_helper_run()
    {
        boost::python::implicitly_convertible<From, clang::ast_matchers::internal::Matcher<T>>();
        Runner run;
    }
};

template<typename From, typename T>
struct implicitly_convertible_helper_run<From, T>
{
    implicitly_convertible_helper_run()
    {
        boost::python::implicitly_convertible<From, clang::ast_matchers::internal::Matcher<T>>();
    }
};

template<typename From, typename... To>
struct implicitly_convertible_helper_impl;

template<typename From, typename... To>
struct implicitly_convertible_helper_impl<From, clang::ast_matchers::internal::TypeList<To...>>
{
    using Runner = implicitly_convertible_helper_run<From, To...>;

    implicitly_convertible_helper_impl()
    {
        Runner run;
    }
};

template<typename MatcherType>
struct implicitly_convertible_helper
{
    using Impl = implicitly_convertible_helper_impl<MatcherType, typename MatcherType::ReturnTypes>;

    implicitly_convertible_helper()
    {
        Impl run;
    }
};

#define STRINGIFY(str) #str

#define EXPOSE_MATCHER(name)                                                        \
    class_<Matcher<name>>(STRINGIFY(name), init<MatcherInterface<name>*>())         \
        .def(init<const Matcher<name>&>())

#define EXPOSE_BINDABLE_MATCHER(name)                                               \
    class_<BindableMatcher<name>, bases<Matcher<name>>>(                            \
        "BindableMatcher_" STRINGIFY(name), init<const Matcher<name>&>())           \
            .def("bind",                                                            \
                +[](BindableMatcher<name> &self, const std::string &id)             \
                {                                                                   \
                    return self.bind(id);                                           \
                }                                                                   \
            )                                                                       \
        ;                                                                           \

template<typename T>
struct make_callable_arg
{
    static auto arg() { return T(); }
};

template<typename U>
struct make_callable_arg<clang::ast_matchers::internal::Matcher<U>>
{
    static auto arg() { return clang::ast_matchers::internal::Matcher<U>(nullptr); }
};

#define EXPOSE_TYPE_TRAVERSE_MATCHER(name, arg)                                                   \
    def(STRINGIFY(name),                                                            \
        +[]()                                                                       \
        {                                                                           \
            return name();                                                          \
        }                                                                           \
    );                                                                              \
    def(STRINGIFY(name),                                                            \
        +[](const Matcher<QualType> &bm)                                                             \
        {                                                                           \
            return name(bm);                                                          \
        }                                                                           \
    );\
    def(STRINGIFY(name),                                                            \
        +[](const Matcher<QualType> &arg1, const Matcher<QualType> &arg2)                                                             \
        {                                                                           \
            return name(arg1, arg2);                                                          \
        }                                                                           \
    );\
    class_<decltype(name(arg))>("typematcher_" STRINGIFY(name), init<ArrayRef<const Matcher<QualType>*>>());\
    implicitly_convertible_helper<decltype(name(arg))>()


#define EXPOSE_OPERATOR_MATCHER_1(name)\
    def(STRINGIFY(name),\
        +[](const Matcher<QualType> &arg1)\
        {\
            return Matcher<QualType>(name(arg1));\
        }\
    );\
    def(STRINGIFY(name),\
        +[](const Matcher<Decl> &arg1)\
        {\
            return Matcher<Decl>(name(arg1));\
        }\
    );

#define EXPOSE_OPERATOR_MATCHER_2(name)\
    def(STRINGIFY(name),\
        +[](const Matcher<QualType> &arg1, const Matcher<QualType> &arg2)\
        {\
            return Matcher<QualType>(name(arg1, arg2));\
        }\
    );\
    def(STRINGIFY(name),\
        +[](const Matcher<Decl> &arg1, const Matcher<Decl> &arg2)\
        {\
            return Matcher<Decl>(name(arg1, arg2));\
        }\
    );

#define DEFINE_ARGUMENT_ADAPTING_MATCHER(name, func)\
    struct name\
    {\
        template<typename... ArgsT>\
        auto call(const ArgsT &... args)\
        {\
            return clang::ast_matchers::func(args...);\
        }\
    }\

DEFINE_ARGUMENT_ADAPTING_MATCHER(Has, has);
DEFINE_ARGUMENT_ADAPTING_MATCHER(HasDescendant, hasDescendant);
DEFINE_ARGUMENT_ADAPTING_MATCHER(ForEach, forEach);
DEFINE_ARGUMENT_ADAPTING_MATCHER(ForEachDescendant, forEachDescendant);
DEFINE_ARGUMENT_ADAPTING_MATCHER(HasParent, hasParent);
DEFINE_ARGUMENT_ADAPTING_MATCHER(HasAncestor, hasAncestor);

#define EXPOSE_AAM(name, func)\
    class_<name>(STRINGIFY(name) "Impl")\
            .def("__call__",\
                +[](name &self, const clang::ast_matchers::internal::Matcher<clang::Decl> &arg)\
                {\
                    return self.call(arg);\
                }\
            )\
            .def("__call__",\
                +[](name &self, const clang::ast_matchers::internal::Matcher<clang::Stmt> &arg)\
                {\
                    return self.call(arg);\
                }\
            );\
    name func;\
    scope().attr(STRINGIFY(func)) = func

#define EXPOSE_ADAPTER(name)\
        class_<typename ArgumentAdaptingMatcherFunc<name>::Adaptor<Decl>>("Adapter_" STRINGIFY(name), init<const Matcher<Decl>&>())\
            .def("__call__",\
                +[](const Matcher<Decl> &arg)\
                {\
                    return ArgumentAdaptingMatcherFunc<name>::Adaptor<Decl>(arg);\
                }\
            )\
        ;\
        implicitly_convertible_helper<typename ArgumentAdaptingMatcherFunc<name>::Adaptor<Decl>>();\
        boost::python::implicitly_convertible<typename ArgumentAdaptingMatcherFunc<name>::Adaptor<Decl>, clang::ast_matchers::internal::Matcher<NamedDecl>>();\
        boost::python::implicitly_convertible<typename ArgumentAdaptingMatcherFunc<name>::Adaptor<Decl>, clang::ast_matchers::internal::Matcher<QualType>>()   

#define EXPOSE_ADAPTER_2(name)\
        using T = TypeList<Decl, NestedNameSpecifierLoc, Stmt, TypeLoc>;\
        class_<typename ArgumentAdaptingMatcherFunc<name, T, T>::Adaptor<Decl>>("Adapter_" STRINGIFY(name) "Decl", init<const Matcher<Decl>&>())\
            .def("__call__",\
                +[](const Matcher<Decl> &arg)\
                {\
                    return ArgumentAdaptingMatcherFunc<name, T, T>::Adaptor<Decl>(arg);\
                }\
            )\
        ;\
        implicitly_convertible_helper<typename ArgumentAdaptingMatcherFunc<name, T, T>::Adaptor<Decl>>();\
        class_<typename ArgumentAdaptingMatcherFunc<name, T, T>::Adaptor<Stmt>>("Adapter_" STRINGIFY(name) "Stmt", init<const Matcher<Stmt>&>())\
            .def("__call__",\
                +[](const Matcher<Stmt> &arg)\
                {\
                    return ArgumentAdaptingMatcherFunc<name, T, T>::Adaptor<Stmt>(arg);\
                }\
            )\
        ;\
        implicitly_convertible_helper<typename ArgumentAdaptingMatcherFunc<name, T, T>::Adaptor<Stmt>>()

BOOST_PYTHON_MODULE(libtooling)
{
    using namespace boost::python;

    void (Tooling::*add_decl)(clang::ast_matchers::DeclarationMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_type)(clang::ast_matchers::TypeMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_stmt)(clang::ast_matchers::StatementMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_nns)(clang::ast_matchers::NestedNameSpecifierMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_nnsl)(clang::ast_matchers::NestedNameSpecifierLocMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_typeloc)(clang::ast_matchers::TypeLocMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_cxxinit)(clang::ast_matchers::CXXCtorInitializerMatcher, boost::python::object) = &Tooling::add;

    class_<Tooling>("Tooling", init<>())
        .def(init<const std::string&>())
        .def("add", add_decl)
        .def("add", add_type)
        .def("add", add_stmt)
        .def("add", add_nns)
        .def("add", add_nnsl)
        .def("add", add_typeloc)
        .def("add", add_cxxinit)
        .def("run", &Tooling::run)
        .def("run_from_source", &Tooling::run_from_source)
    ;

    {
        using namespace clang;
        using namespace clang::ast_matchers;
        using namespace clang::ast_matchers::internal;

        expose_node_matcher();
        expose_poly_matcher();        

        implicitly_convertible<BindableMatcher<Stmt>, Matcher<Expr>>();
        implicitly_convertible<BindableMatcher<Type>, Matcher<QualType>>();
        implicitly_convertible<Matcher<NamedDecl>, Matcher<ParmVarDecl>>();
        implicitly_convertible<Matcher<Type>, Matcher<QualType>>();
        implicitly_convertible<Matcher<Stmt>, Matcher<Expr>>();
        implicitly_convertible<Matcher<ValueDecl>, Matcher<ParmVarDecl>>();

        implicitly_convertible<Matcher<Decl>, Matcher<ParmVarDecl>>();
        //implicitly_convertible<Matcher<NamedDecl>, Matcher<Decl>>();


        expose_simple();
        
        class_<PolymorphicMatcherWithParam1<HasDeclarationMatcher, Matcher<Decl>, void(HasDeclarationSupportedTypes)>>("hasDeclaration_Matcher", init<const Matcher<Decl>&>());
        implicitly_convertible_helper<decltype(hasDeclaration(make_callable_arg<Matcher<Decl>>::arg()))>();
        def("hasDeclaration", hasDeclaration);
        
        class_<PolymorphicMatcherWithParam1<HasOverloadedOperatorNameMatcher,StringRef,AST_POLYMORPHIC_SUPPORTED_TYPES(CXXOperatorCallExpr, FunctionDecl)>>("hasOverloadedOperatorName_Matcher", init<const StringRef&>());
        
        implicitly_convertible_helper<decltype(hasOverloadedOperatorName(make_callable_arg<StringRef>::arg()))>();
        
        def("hasOverloadedOperatorName", 
            +[](const std::string &opname)                                                                       
            {                                                                           
                return clang::ast_matchers::hasOverloadedOperatorName(opname);                                                          
            }
        );

        clang::ast_matchers::internal::Matcher<clang::CXXMethodDecl> a = hasOverloadedOperatorName("*");
        implicitly_convertible<decltype(hasOverloadedOperatorName("*")), Matcher<CXXMethodDecl>>();

        EXPOSE_OPERATOR_MATCHER_1(unless);
        
        EXPOSE_OPERATOR_MATCHER_2(eachOf);
        EXPOSE_OPERATOR_MATCHER_2(anyOf);
        EXPOSE_OPERATOR_MATCHER_2(allOf);

        EXPOSE_TYPE_TRAVERSE_MATCHER(hasElementType, builtinType());        
        EXPOSE_TYPE_TRAVERSE_MATCHER(hasValueType, isInteger()); 
        EXPOSE_TYPE_TRAVERSE_MATCHER(hasDeducedType, isInteger()); 
        EXPOSE_TYPE_TRAVERSE_MATCHER(hasUnderlyingType, isInteger()); 
        EXPOSE_TYPE_TRAVERSE_MATCHER(innerType, functionType()); 

        def("pointee",                                                            
            +[]()                                                                       
            {                                                                           
                return clang::ast_matchers::pointee();                                                          
            }                                                                           
        );                                                                              
        def("pointee",                                                            
            +[](const Matcher<QualType> &bm)                                                            
            {                                                                           
                return clang::ast_matchers::pointee(bm);                                                          
            }                                                                           
        );
        def("pointee",                                                            
            +[](const Matcher<QualType> &arg1, const Matcher<QualType> &arg2)                                                             
            {                                                                           
                return clang::ast_matchers::pointee(arg1, arg2);                                                          
            }                                                                           
        );
        class_<decltype(clang::ast_matchers::pointee(isInteger()))>("typematcher_pointee", init<ArrayRef<const Matcher<QualType>*>>());    
        implicitly_convertible_helper<decltype(clang::ast_matchers::pointee(isInteger()))>();

        expose_bound_nodes();
    }

    expose_wrapper();

    {
        using namespace clang;
        using namespace clang::ast_matchers;
        using namespace clang::ast_matchers::internal;

        EXPOSE_ADAPTER(HasMatcher);
        EXPOSE_ADAPTER(HasDescendantMatcher);      
        EXPOSE_ADAPTER(ForEachMatcher);      
        EXPOSE_ADAPTER(ForEachDescendantMatcher);      
        EXPOSE_ADAPTER_2(HasParentMatcher);      
        EXPOSE_ADAPTER_2(HasAncestorMatcher);      

    }

    EXPOSE_AAM(Has, has);    
    EXPOSE_AAM(HasDescendant, hasDescendant);    
    EXPOSE_AAM(ForEach, forEach);    
    EXPOSE_AAM(ForEachDescendant, forEachDescendant);    
    EXPOSE_AAM(HasParent, hasParent);    
    EXPOSE_AAM(HasAncestor, hasAncestor);    
}

