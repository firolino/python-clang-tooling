#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

void expose_bound_nodes()
{
    using namespace boost::python;

    using namespace clang;
    using namespace clang::ast_matchers;
    using namespace clang::ast_matchers::internal;
    
    class_<BoundNodes>("BoundNodes", init<const BoundNodes&>())
            
        .def("getAccessSpecDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<AccessSpecDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getAddrLabelExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<AddrLabelExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getArraySubscriptExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ArraySubscriptExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getAsmStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<AsmStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getAtomicExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<AtomicExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBinaryConditionalOperator",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BinaryConditionalOperator>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBinaryOperator",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BinaryOperator>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBlockDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BlockDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBlockExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BlockExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBreakStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BreakStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCallExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CallExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCaseStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CaseStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCharacterLiteral",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CharacterLiteral>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getClassTemplateDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ClassTemplateDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCompoundLiteralExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CompoundLiteralExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCompoundStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CompoundStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getConditionalOperator",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ConditionalOperator>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getConstantExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ConstantExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getContinueStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ContinueStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCStyleCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CStyleCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCUDAKernelCallExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CUDAKernelCallExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXBindTemporaryExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXBindTemporaryExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXBoolLiteralExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXBoolLiteralExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXCatchStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXCatchStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXConstCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXConstCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXConstructExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXConstructExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXConstructorDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXConstructorDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXConversionDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXConversionDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXDefaultArgExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXDefaultArgExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXDeleteExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXDeleteExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXDependentScopeMemberExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXDependentScopeMemberExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXDestructorDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXDestructorDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXDynamicCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXDynamicCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXForRangeStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXForRangeStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXFunctionalCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXFunctionalCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXMemberCallExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXMemberCallExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXMethodDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXMethodDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXNewExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXNewExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXNullPtrLiteralExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXNullPtrLiteralExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXOperatorCallExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXOperatorCallExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXRecordDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXRecordDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXReinterpretCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXReinterpretCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXStaticCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXStaticCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXStdInitializerListExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXStdInitializerListExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXTemporaryObjectExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXTemporaryObjectExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXThisExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXThisExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXThrowExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXThrowExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXTryStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXTryStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXUnresolvedConstructExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXUnresolvedConstructExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDeclaratorDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DeclaratorDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getClassTemplatePartialSpecializationDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ClassTemplatePartialSpecializationDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getClassTemplateSpecializationDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ClassTemplateSpecializationDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDeclRefExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DeclRefExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDeclStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DeclStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDefaultStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DefaultStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDesignatedInitExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DesignatedInitExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDoStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DoStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getEnumConstantDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<EnumConstantDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getEnumDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<EnumDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getExplicitCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ExplicitCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<Expr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getExprWithCleanups",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ExprWithCleanups>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFieldDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FieldDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFloatingLiteral",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FloatingLiteral>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getForStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ForStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFriendDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FriendDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFunctionDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FunctionDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFunctionTemplateDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FunctionTemplateDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getGNUNullExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<GNUNullExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getGotoStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<GotoStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getIfStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<IfStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getImaginaryLiteral",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ImaginaryLiteral>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getImplicitCastExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ImplicitCastExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getImplicitValueInitExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ImplicitValueInitExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getIndirectFieldDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<IndirectFieldDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getInitListExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<InitListExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getIntegerLiteral",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<IntegerLiteral>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getLabelDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<LabelDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getLabelStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<LabelStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getLambdaExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<LambdaExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getLinkageSpecDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<LinkageSpecDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getMaterializeTemporaryExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<MaterializeTemporaryExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getMemberExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<MemberExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNamedDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NamedDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNamespaceAliasDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NamespaceAliasDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNamespaceDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NamespaceDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNonTypeTemplateParmDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NonTypeTemplateParmDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNullStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NullStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCAtCatchStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCAtCatchStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCAtFinallyStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCAtFinallyStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCAtThrowStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCAtThrowStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCAtTryStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCAtTryStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCAutoreleasePoolStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCAutoreleasePoolStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCCategoryDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCCategoryDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCCategoryImplDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCCategoryImplDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCImplementationDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCImplementationDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCInterfaceDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCInterfaceDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCIvarDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCIvarDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCIvarRefExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCIvarRefExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCMessageExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCMessageExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCMethodDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCMethodDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCPropertyDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCPropertyDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCProtocolDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCProtocolDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getOpaqueValueExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<OpaqueValueExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getParenExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ParenExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getParenListExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ParenListExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getParmVarDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ParmVarDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getPredefinedExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<PredefinedExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getRecordDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<RecordDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getReturnStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ReturnStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getStaticAssertDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<StaticAssertDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getStmtExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<StmtExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getStringLiteral",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<StringLiteral>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getSubstNonTypeTemplateParmExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<SubstNonTypeTemplateParmExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getSwitchCase",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<SwitchCase>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getSwitchStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<SwitchStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTemplateTypeParmDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TemplateTypeParmDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTranslationUnitDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TranslationUnitDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTypeAliasDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TypeAliasDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTypeAliasTemplateDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TypeAliasTemplateDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTypedefDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TypedefDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTypedefNameDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TypedefNameDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnaryExprOrTypeTraitExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnaryExprOrTypeTraitExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnaryOperator",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnaryOperator>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnresolvedLookupExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnresolvedLookupExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnresolvedMemberExpr",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnresolvedMemberExpr>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnresolvedUsingTypenameDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnresolvedUsingTypenameDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnresolvedUsingValueDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnresolvedUsingValueDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUserDefinedLiteral",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UserDefinedLiteral>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUsingDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UsingDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUsingDirectiveDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UsingDirectiveDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getValueDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ValueDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getVarDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<VarDecl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getWhileStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<WhileStmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getArrayType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ArrayType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getAtomicType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<AtomicType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getAutoType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<AutoType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBlockPointerType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BlockPointerType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getBuiltinType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<BuiltinType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getComplexType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ComplexType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getConstantArrayType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ConstantArrayType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDecayedType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DecayedType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDecltypeType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DecltypeType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDependentSizedArrayType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<DependentSizedArrayType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getElaboratedType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ElaboratedType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getEnumType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<EnumType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFunctionProtoType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FunctionProtoType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getFunctionType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<FunctionType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getIncompleteArrayType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<IncompleteArrayType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getInjectedClassNameType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<InjectedClassNameType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getLValueReferenceType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<LValueReferenceType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getMemberPointerType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<MemberPointerType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getObjCObjectPointerType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ObjCObjectPointerType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getParenType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ParenType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getPointerType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<PointerType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getRecordType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<RecordType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getReferenceType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<ReferenceType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getRValueReferenceType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<RValueReferenceType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getSubstTemplateTypeParmType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<SubstTemplateTypeParmType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTagType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TagType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTemplateSpecializationType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TemplateSpecializationType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTemplateTypeParmType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TemplateTypeParmType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTypedefType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TypedefType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getUnaryTransformType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<UnaryTransformType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getVariableArrayType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<VariableArrayType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getCXXCtorInitializer",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<CXXCtorInitializer>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getDecl",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<Decl>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNestedNameSpecifierLoc",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NestedNameSpecifierLoc>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getNestedNameSpecifier",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<NestedNameSpecifier>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getQualType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<QualType>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getStmt",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<Stmt>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTemplateArgument",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TemplateArgument>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTemplateName",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TemplateName>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getTypeLoc",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<TypeLoc>(id);
            },
            return_value_policy<reference_existing_object>()
        )

        .def("getType",
            +[](BoundNodes &self, const std::string &id)
            {
                return self.getNodeAs<Type>(id);
            },
            return_value_policy<reference_existing_object>()
        )

    ;
}