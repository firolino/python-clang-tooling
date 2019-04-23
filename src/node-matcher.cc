#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

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

namespace pywrappers
{

#define GENERATE_CLANG_WRAPPER(name, func)                                      \
struct name                                                                     \
{                                                                               \
    template<typename... ArgsT>                                                 \
    auto call(const ArgsT &... args)                                    \
    {                                                                           \
        return clang::ast_matchers::func(args...);                              \
    }                                                                           \
}

}

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

#define EXPOSE_POLY_MATCHER(name, paramT, arg)                                      \
    def(STRINGIFY(name),                                                        \
        +[](const paramT &param1)                                                   \
        {                                                                           \
            return name(param1);                                                    \
        }                                                                           \
    );                                                                              \
                                                                                    \
    class_<decltype(name(arg))>("matcher_" STRINGIFY(name), init<const paramT&>()); \
    implicitly_convertible_helper<decltype(name(arg))>()

#define EXPOSE_TYPE_TRAVERSE_MATCHER(name, arg)                                                   \
    def(STRINGIFY(name),                                                            \
        +[]()                                                                       \
        {                                                                           \
            return name();                                                          \
        }                                                                           \
    );                                                                              \
    def(STRINGIFY(name),                                                            \
        +[](Matcher<QualType> bm)                                                             \
        {                                                                           \
            return name(bm);                                                          \
        }                                                                           \
    );\
    def(STRINGIFY(name),                                                            \
        +[](Matcher<QualType> arg1, Matcher<QualType> arg2)                                                             \
        {                                                                           \
            return name(arg1, arg2);                                                          \
        }                                                                           \
    );\
    class_<decltype(name(arg))>("typematcher_" STRINGIFY(name), init<ArrayRef<const Matcher<QualType>*>>());\
    implicitly_convertible_helper<decltype(name(arg))>()

#define EXPOSE_MATCHER_P1(name, paramT, arg)                                        \
    def(STRINGIFY(name), name);                                                     \
    class_<decltype(name(arg))>("matcher_" STRINGIFY(name), init<const paramT&>())  \
    

void expose_node_matcher()
{
    using namespace boost::python;

    using namespace clang;
    using namespace clang::ast_matchers;
    using namespace clang::ast_matchers::internal;

    EXPOSE_MATCHER(AccessSpecDecl);
    EXPOSE_MATCHER(AddrLabelExpr);
    EXPOSE_MATCHER(ArraySubscriptExpr);
    EXPOSE_MATCHER(AsmStmt);
    EXPOSE_MATCHER(AtomicExpr);
    EXPOSE_MATCHER(BinaryConditionalOperator);
    EXPOSE_MATCHER(BinaryOperator);
    EXPOSE_MATCHER(BlockDecl);
    EXPOSE_MATCHER(BlockExpr);
    EXPOSE_MATCHER(BreakStmt);
    EXPOSE_MATCHER(CallExpr);
    EXPOSE_MATCHER(CaseStmt);
    EXPOSE_MATCHER(CastExpr);
    EXPOSE_MATCHER(CharacterLiteral);
    EXPOSE_MATCHER(ClassTemplateDecl);
    EXPOSE_MATCHER(CompoundLiteralExpr);
    EXPOSE_MATCHER(CompoundStmt);
    EXPOSE_MATCHER(ConditionalOperator);
    EXPOSE_MATCHER(ConstantExpr);
    EXPOSE_MATCHER(ContinueStmt);
    EXPOSE_MATCHER(CStyleCastExpr);
    EXPOSE_MATCHER(CUDAKernelCallExpr);
    EXPOSE_MATCHER(CXXBindTemporaryExpr);
    EXPOSE_MATCHER(CXXBoolLiteralExpr);
    EXPOSE_MATCHER(CXXCatchStmt);
    EXPOSE_MATCHER(CXXConstCastExpr);
    EXPOSE_MATCHER(CXXConstructExpr);
    EXPOSE_MATCHER(CXXConstructorDecl);
    EXPOSE_MATCHER(CXXConversionDecl);
    EXPOSE_MATCHER(CXXDefaultArgExpr);
    EXPOSE_MATCHER(CXXDeleteExpr);
    EXPOSE_MATCHER(CXXDependentScopeMemberExpr);
    EXPOSE_MATCHER(CXXDestructorDecl);
    EXPOSE_MATCHER(CXXDynamicCastExpr);
    EXPOSE_MATCHER(CXXForRangeStmt);
    EXPOSE_MATCHER(CXXFunctionalCastExpr);
    EXPOSE_MATCHER(CXXMemberCallExpr);
    EXPOSE_MATCHER(CXXMethodDecl);
    EXPOSE_MATCHER(CXXNewExpr);
    EXPOSE_MATCHER(CXXNullPtrLiteralExpr);
    EXPOSE_MATCHER(CXXOperatorCallExpr);
    EXPOSE_MATCHER(CXXRecordDecl);
    EXPOSE_MATCHER(CXXReinterpretCastExpr);
    EXPOSE_MATCHER(CXXStaticCastExpr);
    EXPOSE_MATCHER(CXXStdInitializerListExpr);
    EXPOSE_MATCHER(CXXTemporaryObjectExpr);
    EXPOSE_MATCHER(CXXThisExpr);
    EXPOSE_MATCHER(CXXThrowExpr);
    EXPOSE_MATCHER(CXXTryStmt);
    EXPOSE_MATCHER(CXXUnresolvedConstructExpr);
    EXPOSE_MATCHER(DeclaratorDecl);
    EXPOSE_MATCHER(ClassTemplatePartialSpecializationDecl);
    EXPOSE_MATCHER(ClassTemplateSpecializationDecl);
    EXPOSE_MATCHER(DeclRefExpr);
    EXPOSE_MATCHER(DeclStmt);
    EXPOSE_MATCHER(DefaultStmt);
    EXPOSE_MATCHER(DesignatedInitExpr);
    EXPOSE_MATCHER(DoStmt);
    EXPOSE_MATCHER(EnumConstantDecl);
    EXPOSE_MATCHER(EnumDecl);
    EXPOSE_MATCHER(ExplicitCastExpr);
    EXPOSE_MATCHER(Expr);
    EXPOSE_MATCHER(ExprWithCleanups);
    EXPOSE_MATCHER(FieldDecl);
    EXPOSE_MATCHER(FloatingLiteral);
    EXPOSE_MATCHER(ForStmt);
    EXPOSE_MATCHER(FriendDecl);
    EXPOSE_MATCHER(FunctionDecl);
    EXPOSE_MATCHER(FunctionTemplateDecl);
    EXPOSE_MATCHER(GNUNullExpr);
    EXPOSE_MATCHER(GotoStmt);
    EXPOSE_MATCHER(IfStmt);
    EXPOSE_MATCHER(ImaginaryLiteral);
    EXPOSE_MATCHER(ImplicitCastExpr);
    EXPOSE_MATCHER(ImplicitValueInitExpr);
    EXPOSE_MATCHER(IndirectFieldDecl);
    EXPOSE_MATCHER(InitListExpr);
    EXPOSE_MATCHER(IntegerLiteral);
    EXPOSE_MATCHER(LabelDecl);
    EXPOSE_MATCHER(LabelStmt);
    EXPOSE_MATCHER(LambdaExpr);
    EXPOSE_MATCHER(LinkageSpecDecl);
    EXPOSE_MATCHER(MaterializeTemporaryExpr);
    EXPOSE_MATCHER(MemberExpr);
    EXPOSE_MATCHER(NamedDecl);
    EXPOSE_MATCHER(NamespaceAliasDecl);
    EXPOSE_MATCHER(NamespaceDecl);
    EXPOSE_MATCHER(NonTypeTemplateParmDecl);
    EXPOSE_MATCHER(NullStmt);
    EXPOSE_MATCHER(ObjCAtCatchStmt);
    EXPOSE_MATCHER(ObjCAtFinallyStmt);
    EXPOSE_MATCHER(ObjCAtThrowStmt);
    EXPOSE_MATCHER(ObjCAtTryStmt);
    EXPOSE_MATCHER(ObjCAutoreleasePoolStmt);
    EXPOSE_MATCHER(ObjCCategoryDecl);
    EXPOSE_MATCHER(ObjCCategoryImplDecl);
    EXPOSE_MATCHER(ObjCImplementationDecl);
    EXPOSE_MATCHER(ObjCInterfaceDecl);
    EXPOSE_MATCHER(ObjCIvarDecl);
    EXPOSE_MATCHER(ObjCIvarRefExpr);
    EXPOSE_MATCHER(ObjCMessageExpr);
    EXPOSE_MATCHER(ObjCMethodDecl);
    EXPOSE_MATCHER(ObjCPropertyDecl);
    EXPOSE_MATCHER(ObjCProtocolDecl);
    EXPOSE_MATCHER(OpaqueValueExpr);
    EXPOSE_MATCHER(ParenExpr);
    EXPOSE_MATCHER(ParenListExpr);
    EXPOSE_MATCHER(ParmVarDecl);
    EXPOSE_MATCHER(PredefinedExpr);
    EXPOSE_MATCHER(RecordDecl);
    EXPOSE_MATCHER(ReturnStmt);
    EXPOSE_MATCHER(StaticAssertDecl);
    EXPOSE_MATCHER(StmtExpr);
    EXPOSE_MATCHER(StringLiteral);
    EXPOSE_MATCHER(SubstNonTypeTemplateParmExpr);
    EXPOSE_MATCHER(SwitchCase);
    EXPOSE_MATCHER(SwitchStmt);
    EXPOSE_MATCHER(TemplateTypeParmDecl);
    EXPOSE_MATCHER(TranslationUnitDecl);
    EXPOSE_MATCHER(TypeAliasDecl);
    EXPOSE_MATCHER(TypeAliasTemplateDecl);
    EXPOSE_MATCHER(TypedefDecl);
    EXPOSE_MATCHER(TypedefNameDecl);
    EXPOSE_MATCHER(UnaryExprOrTypeTraitExpr);
    EXPOSE_MATCHER(UnaryOperator);
    EXPOSE_MATCHER(UnresolvedLookupExpr);
    EXPOSE_MATCHER(UnresolvedMemberExpr);
    EXPOSE_MATCHER(UnresolvedUsingTypenameDecl);
    EXPOSE_MATCHER(UnresolvedUsingValueDecl);
    EXPOSE_MATCHER(UserDefinedLiteral);
    EXPOSE_MATCHER(UsingDecl);
    EXPOSE_MATCHER(UsingDirectiveDecl);
    EXPOSE_MATCHER(ValueDecl);
    EXPOSE_MATCHER(VarDecl);
    EXPOSE_MATCHER(WhileStmt);

    EXPOSE_MATCHER(ArrayType);
    EXPOSE_MATCHER(AtomicType);
    EXPOSE_MATCHER(AutoType);
    EXPOSE_MATCHER(BlockPointerType);
    EXPOSE_MATCHER(BuiltinType);
    EXPOSE_MATCHER(ComplexType);
    EXPOSE_MATCHER(ConstantArrayType);
    EXPOSE_MATCHER(DecayedType);
    EXPOSE_MATCHER(DecltypeType);
    EXPOSE_MATCHER(DependentSizedArrayType);
    EXPOSE_MATCHER(ElaboratedType);
    EXPOSE_MATCHER(EnumType);
    EXPOSE_MATCHER(FunctionProtoType);
    EXPOSE_MATCHER(FunctionType);
    EXPOSE_MATCHER(IncompleteArrayType);
    EXPOSE_MATCHER(InjectedClassNameType);
    EXPOSE_MATCHER(LValueReferenceType);
    EXPOSE_MATCHER(MemberPointerType);
    EXPOSE_MATCHER(ObjCObjectPointerType);
    EXPOSE_MATCHER(ParenType);
    EXPOSE_MATCHER(PointerType);
    EXPOSE_MATCHER(RecordType);
    EXPOSE_MATCHER(ReferenceType);
    EXPOSE_MATCHER(RValueReferenceType);
    EXPOSE_MATCHER(SubstTemplateTypeParmType);
    EXPOSE_MATCHER(TagType);
    EXPOSE_MATCHER(TemplateSpecializationType);
    EXPOSE_MATCHER(TemplateTypeParmType);
    EXPOSE_MATCHER(TypedefType);
    EXPOSE_MATCHER(UnaryTransformType);
    EXPOSE_MATCHER(VariableArrayType);

    EXPOSE_MATCHER(CXXCtorInitializer);
    EXPOSE_MATCHER(Decl);
    EXPOSE_MATCHER(NestedNameSpecifierLoc);
    EXPOSE_MATCHER(NestedNameSpecifier);
    EXPOSE_MATCHER(QualType);
    EXPOSE_MATCHER(Stmt);
    EXPOSE_MATCHER(TemplateArgument);
    EXPOSE_MATCHER(TemplateName);
    EXPOSE_MATCHER(TypeLoc);
    EXPOSE_MATCHER(Type);



    EXPOSE_BINDABLE_MATCHER(AccessSpecDecl);
    EXPOSE_BINDABLE_MATCHER(AddrLabelExpr);
    EXPOSE_BINDABLE_MATCHER(ArraySubscriptExpr);
    EXPOSE_BINDABLE_MATCHER(AsmStmt);
    EXPOSE_BINDABLE_MATCHER(AtomicExpr);
    EXPOSE_BINDABLE_MATCHER(BinaryConditionalOperator);
    EXPOSE_BINDABLE_MATCHER(BinaryOperator);
    EXPOSE_BINDABLE_MATCHER(BlockDecl);
    EXPOSE_BINDABLE_MATCHER(BlockExpr);
    EXPOSE_BINDABLE_MATCHER(BreakStmt);
    EXPOSE_BINDABLE_MATCHER(CallExpr);
    EXPOSE_BINDABLE_MATCHER(CaseStmt);
    EXPOSE_BINDABLE_MATCHER(CastExpr);
    EXPOSE_BINDABLE_MATCHER(CharacterLiteral);
    EXPOSE_BINDABLE_MATCHER(ClassTemplateDecl);
    EXPOSE_BINDABLE_MATCHER(CompoundLiteralExpr);
    EXPOSE_BINDABLE_MATCHER(CompoundStmt);
    EXPOSE_BINDABLE_MATCHER(ConditionalOperator);
    EXPOSE_BINDABLE_MATCHER(ConstantExpr);
    EXPOSE_BINDABLE_MATCHER(ContinueStmt);
    EXPOSE_BINDABLE_MATCHER(CStyleCastExpr);
    EXPOSE_BINDABLE_MATCHER(CUDAKernelCallExpr);
    EXPOSE_BINDABLE_MATCHER(CXXBindTemporaryExpr);
    EXPOSE_BINDABLE_MATCHER(CXXBoolLiteralExpr);
    EXPOSE_BINDABLE_MATCHER(CXXCatchStmt);
    EXPOSE_BINDABLE_MATCHER(CXXConstCastExpr);
    EXPOSE_BINDABLE_MATCHER(CXXConstructExpr);
    EXPOSE_BINDABLE_MATCHER(CXXConstructorDecl);
    EXPOSE_BINDABLE_MATCHER(CXXConversionDecl);
    EXPOSE_BINDABLE_MATCHER(CXXDefaultArgExpr);
    EXPOSE_BINDABLE_MATCHER(CXXDeleteExpr);
    EXPOSE_BINDABLE_MATCHER(CXXDependentScopeMemberExpr);
    EXPOSE_BINDABLE_MATCHER(CXXDestructorDecl);
    EXPOSE_BINDABLE_MATCHER(CXXDynamicCastExpr);
    EXPOSE_BINDABLE_MATCHER(CXXForRangeStmt);
    EXPOSE_BINDABLE_MATCHER(CXXFunctionalCastExpr);
    EXPOSE_BINDABLE_MATCHER(CXXMemberCallExpr);
    EXPOSE_BINDABLE_MATCHER(CXXMethodDecl);
    EXPOSE_BINDABLE_MATCHER(CXXNewExpr);
    EXPOSE_BINDABLE_MATCHER(CXXNullPtrLiteralExpr);
    EXPOSE_BINDABLE_MATCHER(CXXOperatorCallExpr);
    EXPOSE_BINDABLE_MATCHER(CXXRecordDecl);
    EXPOSE_BINDABLE_MATCHER(CXXReinterpretCastExpr);
    EXPOSE_BINDABLE_MATCHER(CXXStaticCastExpr);
    EXPOSE_BINDABLE_MATCHER(CXXStdInitializerListExpr);
    EXPOSE_BINDABLE_MATCHER(CXXTemporaryObjectExpr);
    EXPOSE_BINDABLE_MATCHER(CXXThisExpr);
    EXPOSE_BINDABLE_MATCHER(CXXThrowExpr);
    EXPOSE_BINDABLE_MATCHER(CXXTryStmt);
    EXPOSE_BINDABLE_MATCHER(CXXUnresolvedConstructExpr);
    EXPOSE_BINDABLE_MATCHER(DeclaratorDecl);
    EXPOSE_BINDABLE_MATCHER(ClassTemplatePartialSpecializationDecl);
    EXPOSE_BINDABLE_MATCHER(ClassTemplateSpecializationDecl);
    EXPOSE_BINDABLE_MATCHER(DeclRefExpr);
    EXPOSE_BINDABLE_MATCHER(DeclStmt);
    EXPOSE_BINDABLE_MATCHER(DefaultStmt);
    EXPOSE_BINDABLE_MATCHER(DesignatedInitExpr);
    EXPOSE_BINDABLE_MATCHER(DoStmt);
    EXPOSE_BINDABLE_MATCHER(EnumConstantDecl);
    EXPOSE_BINDABLE_MATCHER(EnumDecl);
    EXPOSE_BINDABLE_MATCHER(ExplicitCastExpr);
    EXPOSE_BINDABLE_MATCHER(Expr);
    EXPOSE_BINDABLE_MATCHER(ExprWithCleanups);
    EXPOSE_BINDABLE_MATCHER(FieldDecl);
    EXPOSE_BINDABLE_MATCHER(FloatingLiteral);
    EXPOSE_BINDABLE_MATCHER(ForStmt);
    EXPOSE_BINDABLE_MATCHER(FriendDecl);
    EXPOSE_BINDABLE_MATCHER(FunctionDecl);
    EXPOSE_BINDABLE_MATCHER(FunctionTemplateDecl);
    EXPOSE_BINDABLE_MATCHER(GNUNullExpr);
    EXPOSE_BINDABLE_MATCHER(GotoStmt);
    EXPOSE_BINDABLE_MATCHER(IfStmt);
    EXPOSE_BINDABLE_MATCHER(ImaginaryLiteral);
    EXPOSE_BINDABLE_MATCHER(ImplicitCastExpr);
    EXPOSE_BINDABLE_MATCHER(ImplicitValueInitExpr);
    EXPOSE_BINDABLE_MATCHER(IndirectFieldDecl);
    EXPOSE_BINDABLE_MATCHER(InitListExpr);
    EXPOSE_BINDABLE_MATCHER(IntegerLiteral);
    EXPOSE_BINDABLE_MATCHER(LabelDecl);
    EXPOSE_BINDABLE_MATCHER(LabelStmt);
    EXPOSE_BINDABLE_MATCHER(LambdaExpr);
    EXPOSE_BINDABLE_MATCHER(LinkageSpecDecl);
    EXPOSE_BINDABLE_MATCHER(MaterializeTemporaryExpr);
    EXPOSE_BINDABLE_MATCHER(MemberExpr);
    EXPOSE_BINDABLE_MATCHER(NamedDecl);
    EXPOSE_BINDABLE_MATCHER(NamespaceAliasDecl);
    EXPOSE_BINDABLE_MATCHER(NamespaceDecl);
    EXPOSE_BINDABLE_MATCHER(NonTypeTemplateParmDecl);
    EXPOSE_BINDABLE_MATCHER(NullStmt);
    EXPOSE_BINDABLE_MATCHER(ObjCAtCatchStmt);
    EXPOSE_BINDABLE_MATCHER(ObjCAtFinallyStmt);
    EXPOSE_BINDABLE_MATCHER(ObjCAtThrowStmt);
    EXPOSE_BINDABLE_MATCHER(ObjCAtTryStmt);
    EXPOSE_BINDABLE_MATCHER(ObjCAutoreleasePoolStmt);
    EXPOSE_BINDABLE_MATCHER(ObjCCategoryDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCCategoryImplDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCImplementationDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCInterfaceDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCIvarDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCIvarRefExpr);
    EXPOSE_BINDABLE_MATCHER(ObjCMessageExpr);
    EXPOSE_BINDABLE_MATCHER(ObjCMethodDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCPropertyDecl);
    EXPOSE_BINDABLE_MATCHER(ObjCProtocolDecl);
    EXPOSE_BINDABLE_MATCHER(OpaqueValueExpr);
    EXPOSE_BINDABLE_MATCHER(ParenExpr);
    EXPOSE_BINDABLE_MATCHER(ParenListExpr);
    EXPOSE_BINDABLE_MATCHER(ParmVarDecl);
    EXPOSE_BINDABLE_MATCHER(PredefinedExpr);
    EXPOSE_BINDABLE_MATCHER(RecordDecl);
    EXPOSE_BINDABLE_MATCHER(ReturnStmt);
    EXPOSE_BINDABLE_MATCHER(StaticAssertDecl);
    EXPOSE_BINDABLE_MATCHER(StmtExpr);
    EXPOSE_BINDABLE_MATCHER(StringLiteral);
    EXPOSE_BINDABLE_MATCHER(SubstNonTypeTemplateParmExpr);
    EXPOSE_BINDABLE_MATCHER(SwitchCase);
    EXPOSE_BINDABLE_MATCHER(SwitchStmt);
    EXPOSE_BINDABLE_MATCHER(TemplateTypeParmDecl);
    EXPOSE_BINDABLE_MATCHER(TranslationUnitDecl);
    EXPOSE_BINDABLE_MATCHER(TypeAliasDecl);
    EXPOSE_BINDABLE_MATCHER(TypeAliasTemplateDecl);
    EXPOSE_BINDABLE_MATCHER(TypedefDecl);
    EXPOSE_BINDABLE_MATCHER(TypedefNameDecl);
    EXPOSE_BINDABLE_MATCHER(UnaryExprOrTypeTraitExpr);
    EXPOSE_BINDABLE_MATCHER(UnaryOperator);
    EXPOSE_BINDABLE_MATCHER(UnresolvedLookupExpr);
    EXPOSE_BINDABLE_MATCHER(UnresolvedMemberExpr);
    EXPOSE_BINDABLE_MATCHER(UnresolvedUsingTypenameDecl);
    EXPOSE_BINDABLE_MATCHER(UnresolvedUsingValueDecl);
    EXPOSE_BINDABLE_MATCHER(UserDefinedLiteral);
    EXPOSE_BINDABLE_MATCHER(UsingDecl);
    EXPOSE_BINDABLE_MATCHER(UsingDirectiveDecl);
    EXPOSE_BINDABLE_MATCHER(ValueDecl);
    EXPOSE_BINDABLE_MATCHER(VarDecl);
    EXPOSE_BINDABLE_MATCHER(WhileStmt);

    EXPOSE_BINDABLE_MATCHER(ArrayType);
    EXPOSE_BINDABLE_MATCHER(AtomicType);
    EXPOSE_BINDABLE_MATCHER(AutoType);
    EXPOSE_BINDABLE_MATCHER(BlockPointerType);
    EXPOSE_BINDABLE_MATCHER(BuiltinType);
    EXPOSE_BINDABLE_MATCHER(ComplexType);
    EXPOSE_BINDABLE_MATCHER(ConstantArrayType);
    EXPOSE_BINDABLE_MATCHER(DecayedType);
    EXPOSE_BINDABLE_MATCHER(DecltypeType);
    EXPOSE_BINDABLE_MATCHER(DependentSizedArrayType);
    EXPOSE_BINDABLE_MATCHER(ElaboratedType);
    EXPOSE_BINDABLE_MATCHER(EnumType);
    EXPOSE_BINDABLE_MATCHER(FunctionProtoType);
    EXPOSE_BINDABLE_MATCHER(FunctionType);
    EXPOSE_BINDABLE_MATCHER(IncompleteArrayType);
    EXPOSE_BINDABLE_MATCHER(InjectedClassNameType);
    EXPOSE_BINDABLE_MATCHER(LValueReferenceType);
    EXPOSE_BINDABLE_MATCHER(MemberPointerType);
    EXPOSE_BINDABLE_MATCHER(ObjCObjectPointerType);
    EXPOSE_BINDABLE_MATCHER(ParenType);
    EXPOSE_BINDABLE_MATCHER(PointerType);
    EXPOSE_BINDABLE_MATCHER(RecordType);
    EXPOSE_BINDABLE_MATCHER(ReferenceType);
    EXPOSE_BINDABLE_MATCHER(RValueReferenceType);
    EXPOSE_BINDABLE_MATCHER(SubstTemplateTypeParmType);
    EXPOSE_BINDABLE_MATCHER(TagType);
    EXPOSE_BINDABLE_MATCHER(TemplateSpecializationType);
    EXPOSE_BINDABLE_MATCHER(TemplateTypeParmType);
    EXPOSE_BINDABLE_MATCHER(TypedefType);
    EXPOSE_BINDABLE_MATCHER(UnaryTransformType);
    EXPOSE_BINDABLE_MATCHER(VariableArrayType);

    EXPOSE_BINDABLE_MATCHER(CXXCtorInitializer);
    EXPOSE_BINDABLE_MATCHER(Decl);
    EXPOSE_BINDABLE_MATCHER(NestedNameSpecifierLoc);
    EXPOSE_BINDABLE_MATCHER(NestedNameSpecifier);
    EXPOSE_BINDABLE_MATCHER(QualType);
    EXPOSE_BINDABLE_MATCHER(Stmt);
    EXPOSE_BINDABLE_MATCHER(TemplateArgument);
    EXPOSE_BINDABLE_MATCHER(TemplateName);
    EXPOSE_BINDABLE_MATCHER(TypeLoc);
    EXPOSE_BINDABLE_MATCHER(Type);
}