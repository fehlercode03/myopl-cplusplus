#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <memory>

#include "token.hpp"
#include "nodes.hpp"

class Parser {
	public:
		int tok_idx = -1;
		std::vector<Token> tokens;
		Token currentToken;

		Parser();
		Parser(std::vector<Token> t);
		
		Token advance();
		std::unique_ptr<NumberNode> factor();
		std::unique_ptr<Node> term();
		std::unique_ptr<Node> expr();
		std::unique_ptr<Node> parse();
		std::unique_ptr<Node> binop(std::string funcName, std::vector<TokenType> ops);
};

#endif // PARSER_HPP_
