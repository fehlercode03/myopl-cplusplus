#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>

#include "consts.hpp"

enum TokenType: char {
	TT_INT = 0x49,
	TT_FLOAT = 0x46,
	TT_PLUS = 0x2b,
	TT_MINUS = 0x2d,
	TT_MUL = 0x2a,
	TT_DIV = 0x2f,
	TT_RPAREN = 0x28,
	TT_LPAREN = 0x29
};

class Token {
	public:
		std::string value;
		TokenType type;
		int intValue = 0;
		double doubleValue = 0.0;

		Token();
		Token(TokenType t, std::string v = NULL_STR);
		
		std::string asString();
		
};

std::string tokenTypeToString(TokenType t);

#endif // TOKEN_HPP_
