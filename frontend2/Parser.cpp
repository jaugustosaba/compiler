#include "Parser.h"
#include "Ident.h"
#include "IdentList.h"
#include "Decls.h"
#include "Var.h"
#include "Procedure.h"
#include "FParam.h"
#include "BinExpr.h"
#include "UnExpr.h"

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
		consume(TokenType::Module);
		parseIdent(module->id);
		consume(TokenType::Semi);
		parseDecls(module->decls);
		if (m_lexer.peek() == TokenType::Begin) {
			m_lexer.next();
			parseStmts();
		}
		consume(TokenType::End);
		Ident id;
		parseIdent(id);
		if (module->id.text.compare(id.text)) {

		}
		consume(TokenType::Dot);
		return module;
	}
	void parseIdent(Ident &ident) {
		if (m_lexer.peek() != TokenType::Id) {
			syntaxError({TokenType::Id});
		}
		ident.from = m_lexer.from();
		ident.to = m_lexer.to();
		ident.text = m_lexer.lexeme();
	}
	IdentList::IdentPtr parseIdent() {
		IdentList::IdentPtr ident(new Ident());
		parseIdent(*ident);
		return std::move(ident);
	}
	void parseDecls(Decls &decls) {
		parseVars(decls.vars);
		parseProcs(decls.procedures);
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
		parseStmts();
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
		std::unique_ptr<FParam> fparam(new FParam{});
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
	void parseStmts() {
		while (m_lexer.peek() != TokenType::End) {
			parseStmts();
			consume(TokenType::Semi);
		}
	}
	void parseStmt() {
		switch (m_lexer.peek()) {
		case TokenType::If:
			parseIf();
			break;
		case TokenType::While:
			parseWhile();
			break;
		case TokenType::Return:
			parseReturn();
			break;
		default:
			parseDesignator();
			if (m_lexer.peek() == TokenType::Assign) {
				parseAssign();
			} else {
				parseCall();
			}
		}
	}
	void parseIf() {
		m_lexer.next();
		parseExpr();
		consume(TokenType::Then);
		parseStmts();
		while (m_lexer.peek() == TokenType::Elseif) {
			m_lexer.next();
			parseExpr();
			consume(TokenType::Then);
			parseStmts();
		}
		if (m_lexer.peek() == TokenType::Else) {
			m_lexer.next();
			parseStmts();
		}
		consume(TokenType::End);
	}
	void parseWhile() {
		m_lexer.next();
		parseExpr();
		consume(TokenType::Do);
		parseStmts();
		consume(TokenType::End);
	}
	void parseReturn() {
		m_lexer.next();
		if (m_lexer.peek() != TokenType::Semi) {
			parseExpr();
		}
	}
	void parseDesignator() {
		consume(TokenType::Id);
	}
	void parseAssign() {
		m_lexer.next();
		parseExpr();
	}
	void parseCall() {
		parseAParams();
	}
	void parseAParams() {
		if (m_lexer.peek() == TokenType::LParen) {
			m_lexer.next();
			if (m_lexer.peek() != TokenType::RParen) {
				parseExpr();
				while (m_lexer.peek() == TokenType::Comma) {
					m_lexer.next();
					parseExpr();
				}
			}
			m_lexer.next();
		}
	}
	Expr::ExprPtr parseExpr() {
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
			BinExpr::BinExprPtr binexpr(new BinExpr());
			binexpr->op = op;
			binexpr->left = std::move(expr);
			binexpr->right = parseAddExpr();
			expr = std::move(binexpr);
		}
		return expr;
	}
	Expr::ExprPtr parseAddExpr() {
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
				BinExpr::BinExprPtr binexpr(new BinExpr());
				binexpr->op = op;
				binexpr->left = std::move(expr);
				binexpr->right = parseMulExpr();
				expr = std::move(binexpr);
			}
		}
		return expr;
	}
	Expr::ExprPtr parseMulExpr() {
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
				BinExpr::BinExprPtr binexpr(new BinExpr());
				binexpr->op = op;
				binexpr->left = std::move(expr);
				binexpr->right = parseSingleExpr();
				expr = std::move(binexpr);
			}
		}
		return expr;
	}
	inline
	Expr::ExprPtr makeUnExpr(UnOp op, Expr::ExprPtr &&expr) {
		UnExpr::UnExprPtr unexpr(new UnExpr());
		unexpr->op = op;
		unexpr->expr = std::move(expr);
		return std::move(unexpr);
	}
	Expr::ExprPtr parseSingleExpr() {
		Expr::ExprPtr expr;
		switch (m_lexer.peek()) {
		case TokenType::Not:
		{
			m_lexer.next();
			expr = makeUnExpr(UnOp::Not, parseSingleExpr());
			break;
		}
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
			m_lexer.next();
			break;
		case TokenType::True:
		case TokenType::False:
			m_lexer.next();
			break;
		default:
			parseDesignator();
			parseAParams();
		}
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

Parser::ModulePtr Parser::parse() {
	m_lexer.next();
	Helper helper(m_lexer);
	return helper.parseModule();
}
} // namespace frontend



