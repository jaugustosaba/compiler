#include "Parser.h"
#include "Ident.h"
#include "IdentList.h"
#include "Decls.h"
#include "Var.h"
#include "Procedure.h"
#include "FParam.h"
#include "BinExpr.h"
#include "UnExpr.h"
#include "IdDesignator.h"
#include "CallExpr.h"
#include "BoolExpr.h"
#include "IntExpr.h"
#include "CallStmt.h"
#include "AssignStmt.h"
#include "IfStmt.h"
#include "WhileStmt.h"
#include "ReturnStmt.h"

namespace frontend {

const char* SyntaxError::what() const noexcept {
	return "syntax error";
}

SyntaxError::~SyntaxError() noexcept {
}

class Parser::Helper {
	Lexer &m_lexer;
public:
	Helper(Lexer &lexer)
		: m_lexer(lexer)
	{
	}

	ModulePtr parseModule() {
		ModulePtr module(new Module());
		module->from = m_lexer.from();
		consume(TokenType::Module);
		parseIdent(module->id);
		consume(TokenType::Semi);
		parseDecls(module->decls);
		if (m_lexer.peek() == TokenType::Begin) {
			m_lexer.next();
			parseStmts(module->stmts);
		}
		consume(TokenType::End);
		Ident id;
		parseIdent(id);
		if (module->id.value.compare(id.value)) {

		}
		consume(TokenType::Dot);
		module->to = m_lexer.to();
		return module;
	}
private:

	void parseIdent(Ident &ident) {
		if (m_lexer.peek() != TokenType::Id) {
			syntaxError({TokenType::Id});
		}
		ident.from = m_lexer.from();
		m_lexer.next();
		ident.to = m_lexer.to();
		ident.value = m_lexer.lexeme();
	}
	IdentList::IdentPtr parseIdent() {
		IdentList::IdentPtr ident(new Ident());
		parseIdent(*ident);
		return std::move(ident);
	}
	void parseDecls(Decls &decls) {
		decls.from = m_lexer.from();
		parseVars(decls.vars);
		parseProcs(decls.procedures);
		decls.to = m_lexer.to();
	}
	void parseVars(Decls::VarVect &vars) {
		while (m_lexer.peek() == TokenType::Var) {
			m_lexer.next();
			while (m_lexer.peek() == TokenType::Id) {
				parseVar(vars);
			}
		}
	}
	void parseVar(Decls::VarVect &vars) {
		Decls::VarPtr var(new Var());
		var->from = m_lexer.from();
		parseIdentList(var->identList);
		consume(TokenType::Colon);
		parseIdent(var->typeName);
		consume(TokenType::Semi);
		var->to = m_lexer.from();
		vars.push_back(std::move(var));
	}
	void parseIdentList(IdentList &identList) {
		identList.from = m_lexer.from();
		identList.idents.push_back(parseIdent());
		while (m_lexer.peek() == TokenType::Comma) {
			m_lexer.next();
			identList.idents.push_back(parseIdent());
		}
		identList.to = m_lexer.from();
	}
	void parseProcs(Decls::ProcedureVect &procs) {
		while (m_lexer.peek() == TokenType::Procedure) {
			parseProc(procs);
		}
	}
	void parseProc(Decls::ProcedureVect &procs) {
		Decls::ProcedurePtr procedure(new Procedure());
		procedure->from = m_lexer.from();
		m_lexer.next();
		parseIdent(procedure->id);
		if (m_lexer.peek() == TokenType::LParen) {
			m_lexer.next();
			parseFParams(procedure->fparams);
			consume(TokenType::RParen);
		}
		if (m_lexer.peek() == TokenType::Colon) {
			m_lexer.next();
			consume(TokenType::Id);
		}
		consume(TokenType::Semi);
		parseDecls(procedure->decls);
		consume(TokenType::Begin);
		parseStmts(procedure->stmts);
		consume(TokenType::End);
		consume(TokenType::Id);
		consume(TokenType::Semi);
		procedure->to = m_lexer.to();
		procs.push_back(std::move(procedure));
	}
	void parseFParams(Procedure::FParamVect &fparams) {
		parseFParam(fparams);
		while (m_lexer.peek() == TokenType::Semi) {
			m_lexer.next();
			parseFParam(fparams);
		}
	}
	void parseFParam(Procedure::FParamVect &fparams) {
		FParamPtr fparam(new FParam{});
		fparam->from = m_lexer.from();
		if (m_lexer.peek() == TokenType::Var) {
			m_lexer.next();
			fparam->isVar = true;
		}
		parseIdentList(fparam->identList);
		consume(TokenType::Colon);
		parseIdent(fparam->typeName);
		fparam->to = m_lexer.to();
		fparams.push_back(std::move(fparam));
	}
	void parseStmts(StmtList &stmts) {
		stmts.from = m_lexer.from();
		while (m_lexer.peek() != TokenType::End) {
			stmts.stmts.push_back(parseStmt());
			consume(TokenType::Semi);
		}
		stmts.to = m_lexer.to();
	}
	StmtPtr parseStmt() {
		switch (m_lexer.peek()) {
		case TokenType::If:
			return parseIf();
		case TokenType::While:
			return parseWhile();
		case TokenType::Return:
			return parseReturn();
		default:
			auto desig = parseDesignator();
			if (m_lexer.peek() == TokenType::Assign) {
				return parseAssign(std::move(desig));
			}
			return parseCall(std::move(desig));
		}
	}
	IfStmtPtr parseIf() {
		IfStmtPtr ifStmt(new IfStmt());
		ifStmt->from = m_lexer.from();
		m_lexer.next();
		ifStmt->condition = parseExpr();
		consume(TokenType::Then);
		parseStmts(ifStmt->stmts);
		while (m_lexer.peek() == TokenType::Elseif) {
			ElseifPtr elseif(new Elseif());
			m_lexer.next();
			elseif->condition = parseExpr();
			consume(TokenType::Then);
			parseStmts(elseif->stmts);
			ifStmt->elseifs.push_back(std::move(elseif));
		}
		if (m_lexer.peek() == TokenType::Else) {
			m_lexer.next();
			parseStmts(ifStmt->elseStmts);
		}
		consume(TokenType::End);
		ifStmt->to = m_lexer.from();
		return std::move(ifStmt);
	}
	WhileStmtPtr parseWhile() {
		WhileStmtPtr whileStmt(new WhileStmt());
		whileStmt->from = m_lexer.from();
		m_lexer.next();
		whileStmt->condition = parseExpr();
		consume(TokenType::Do);
		parseStmts(whileStmt->stmts);
		consume(TokenType::End);
		whileStmt->to = m_lexer.from();
		return std::move(whileStmt);
	}
	ReturnStmtPtr parseReturn() {
		ReturnStmtPtr returnStmt(new ReturnStmt());
		returnStmt->from = m_lexer.from();
		m_lexer.next();
		if (m_lexer.peek() != TokenType::Semi) {
			returnStmt->expr = parseExpr();
		}
		returnStmt->to = m_lexer.from();
		return std::move(returnStmt);
	}
	DesignatorPtr parseDesignator() {
		if (m_lexer.peek() != TokenType::Id) {
			syntaxError({TokenType::Id});
		}
		IdDesignatorPtr idDesig(new IdDesignator());
		idDesig->from = m_lexer.from();
		idDesig->value = m_lexer.lexeme();
		m_lexer.next();
		idDesig->to = m_lexer.to();
		return std::move(idDesig);
	}
	AssignStmtPtr parseAssign(DesignatorPtr &&designator) {
		AssignStmtPtr assignStmt(new AssignStmt());
		assignStmt->from = designator->from;
		m_lexer.next();
		assignStmt->designator = std::move(designator);
		assignStmt->expr = parseExpr();
		assignStmt->to = assignStmt->expr->to;
		return std::move(assignStmt);
	}
	CallStmtPtr parseCall(DesignatorPtr &&designator) {
		CallStmtPtr callStmt(new CallStmt());
		callStmt->from = designator->from;
		callStmt->designator = std::move(designator);
		callStmt->to = designator->to;
		parseAParams(*callStmt);
		return std::move(callStmt);
	}
	void parseAParams(Call &call) {
		if (m_lexer.peek() == TokenType::LParen) {
			m_lexer.next();
			if (m_lexer.peek() != TokenType::RParen) {
				call.aparams.push_back(parseExpr());
				while (m_lexer.peek() == TokenType::Comma) {
					m_lexer.next();
					call.aparams.push_back(parseExpr());
				}
			}
			m_lexer.next();
		}
	}
	inline
	ExprPtr makeBinExpr(BinOp op, ExprPtr &&left, ExprPtr &&right) {
		BinExprPtr binexpr(new BinExpr());
		binexpr->from = left->from;
		binexpr->to = right->to;
		binexpr->op = op;
		binexpr->left = std::move(left);
		binexpr->right = std::move(right);
		return std::move(binexpr);
	}
	ExprPtr parseExpr() {
		auto expr = parseAddExpr();
		BinOp op;
		bool flag = true;
		switch (m_lexer.peek()) {
		case TokenType::Eq:
			op = BinOp::Eq;
			break;
		case TokenType::Ne:
			op = BinOp::Ne;
			break;
		case TokenType::Le:
			op = BinOp::Le;
			break;
		case TokenType::Lt:
			op = BinOp::Lt;
			break;
		case TokenType::Ge:
			op = BinOp::Ge;
			break;
		case TokenType::Gt:
			op = BinOp::Gt;
			break;
		default:
			flag = false;
			break;
		}
		if (flag) {
			m_lexer.next();
			expr = makeBinExpr(op, std::move(expr), parseAddExpr());
		}
		return expr;
	}
	ExprPtr parseAddExpr() {
		auto expr = parseMulExpr();
		bool flag = true;
		while (flag) {
			BinOp op;
			switch (m_lexer.peek()) {
			case TokenType::Add:
				op = BinOp::Add;
				break;
			case TokenType::Sub:
				op = BinOp::Sub;
				break;
			case TokenType::Or:
				op = BinOp::Or;
				break;
			default:
				flag = false;
				break;
			}
			if (flag) {
				m_lexer.next();
				expr = makeBinExpr(op, std::move(expr), parseMulExpr());
			}
		}
		return expr;
	}
	ExprPtr parseMulExpr() {
		auto expr = parseSingleExpr();
		bool flag = true;
		while (flag) {
			BinOp op;
			switch (m_lexer.peek()) {
			case TokenType::Mul:
				op = BinOp::Mul;
				break;
			case TokenType::RealDiv:
				op = BinOp::RealDiv;
				break;
			case TokenType::Div:
				op = BinOp::Div;
				break;
			case TokenType::Mod:
				op = BinOp::Mod;
				break;
			case TokenType::And:
				op = BinOp::And;
				break;
			default:
				flag = false;
				break;
			}
			if (flag) {
				m_lexer.next();
				expr = makeBinExpr(op, std::move(expr), parseSingleExpr());
			}
		}
		return expr;
	}
	inline
	ExprPtr makeUnExpr(UnOp op, ExprPtr &&expr) {
		UnExprPtr unexpr(new UnExpr());
		unexpr->op = op;
		unexpr->expr = std::move(expr);
		return std::move(unexpr);
	}
	inline
	BoolExprPtr makeBoolExpr(const std::string &value) {
		BoolExprPtr boolExpr(new BoolExpr());
		boolExpr->value = value;
		return std::move(boolExpr);
	}
	inline
	IntExprPtr makeIntExpr(const std::string &value) {
		IntExprPtr intExpr(new IntExpr());
		intExpr->value = value;
		return std::move(intExpr);
	}
	ExprPtr parseSingleExpr() {
		auto from = m_lexer.from();
		ExprPtr expr;
		switch (m_lexer.peek()) {
		case TokenType::Not:
			m_lexer.next();
			expr = makeUnExpr(UnOp::Not, parseSingleExpr());
			break;
		case TokenType::Add:
			m_lexer.next();
			expr = parseSingleExpr();
			break;
		case TokenType::Sub:
			m_lexer.next();
			expr = makeUnExpr(UnOp::Neg, parseSingleExpr());
			break;
		case TokenType::LParen:
			m_lexer.next();
			expr = parseExpr();
			consume(TokenType::RParen);
			break;
		case TokenType::Int:
			expr = makeIntExpr(m_lexer.lexeme());
			m_lexer.next();
			break;
		case TokenType::True:
			expr = makeBoolExpr(m_lexer.lexeme());
			m_lexer.next();
			break;
		case TokenType::False:
			expr = makeBoolExpr(m_lexer.lexeme());
			m_lexer.next();
			break;
		default:
		{
			CallExprPtr callExpr(new CallExpr());
			callExpr->designator = parseDesignator();
			parseAParams(*callExpr);
			expr = std::move(callExpr);
		}
		}
		expr->from = from;
		expr->to = m_lexer.from();
		return expr;
	}
	void consume(TokenType tt) {
		auto tk = m_lexer.peek();
		if (tk != tt) {
			syntaxError({tt});
		}
		m_lexer.next();
	}
	void syntaxError(std::initializer_list<TokenType> expecting) {
		throw SyntaxError();
	}
};

ModulePtr Parser::parse() {
	m_lexer.next();
	Helper helper(m_lexer);
	return helper.parseModule();
}
} // namespace frontend



