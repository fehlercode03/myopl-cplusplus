#ifndef CONSTS_HPP_
#define CONSTS_HPP_

// #include <map>
#include <string>
/*
const std::string
	TT_INT = "INT", TT_FLOAT = "FLOAT",
	TT_PLUS = "PLUS", TT_MINUS = "MINUS",
	TT_MUL = "MUL", TT_DIV = "DIV",
	TT_RPAREN = "RPAREN", TT_LPAREN = "LPAREN"
;
*/

const std::string NULL_STR = "\0";

/*
const std::map<std::string, std::string> tokensMap = {
	{"+", TT_PLUS}, {"-", TT_MINUS}, {"*", TT_MUL},
	{"/", TT_DIV}, {"(", TT_RPAREN}, {")", TT_LPAREN}
};
*/
const std::string validTokens = "+-*/()";

#endif // CONSTS_HPP_
