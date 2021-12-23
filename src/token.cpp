#include <string>

#include "consts.hpp"
// #include "utils.hpp"

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

std::string tokenTypeToString(TokenType t);

class Token {
	public:
		std::string value;
		TokenType type;
		int intValue = 0;
		double doubleValue = 0.0;
		
		std::string asString() {
			std::string stringType = tokenTypeToString(this->type);
			// https://www.dummies.com/programming/c/how-to-use-the-decision-making-function-in-c-programming/
			return (this->value != NULL_STR) ? stringType + ": " + this->value : stringType;
		};

		Token(){};
		Token(TokenType t, std::string v = NULL_STR){
			type = t;
			if (t == TT_INT){ intValue = std::stoi(v); }
			else if (t == TT_FLOAT){ doubleValue = std::stod(v); }
			value = v;
		}

};

std::string tokenTypeToString(TokenType t) {
	std::string s = std::string(1, (char) t);
	if (s == "I") return "INT";
	else if (s == "F") return "FLOAT";
	else if (s == "+") return "PLUS";
	else if (s == "-") return "MINUS";
	else if (s == "*") return "MUL";
	else if (s == "/") return "DIV";
	else if (s == "(") return "RPAREN";
	else if (s == ")") return "LPAREN";
	else return "UNKNOWN";
};

// this is a comment to make make think i changed something
