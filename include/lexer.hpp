#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <string>

#include "token.hpp"
#include "utils.hpp"
#include "position.hpp"

class Lexer {
	public:
		std::string text, currentChar, fileName;
		Position pos;

		Lexer();
		Lexer(std::string fN, std::string t);
		int advance();
		Token makeNumber();
		tokenErrorPair makeTokens();
};

#endif // LEXER_HPP_
