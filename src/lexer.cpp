#include <vector>
#include <string>

#include "token.hpp"
#include "consts.hpp"
#include "utils.hpp"
#include "errors.hpp"
#include "position.hpp"

class Lexer {
	private:
		// Private variables
		std::string text;
		Position pos;
		std::string currentChar, fileName;

		int advance(){
			// Increment the counter
			this->pos.advance(this->currentChar);
			// lib/token.hpp:18
			this->currentChar = (this->pos.idx < this->text.length()) ? std::string(1, this->text[this->pos.idx]) : NULL_STR;
			return 0;
		};

	public:
		Lexer();
		// Initializer
		Lexer(std::string fN, std::string t){
			fileName = fN;
			text = t;
			pos = Position({
				.idx = -1,
				.ln = 0, 
				.col = -1,
				.fileName = fN,
				.fileText = t
			});
			this->advance();
		};

		// Function to make a number
		Token makeNumber(){
			std::string numStr;
			int dotCount = 0;

			while (isDotOrDigit(this->currentChar)){
				if (this->currentChar == ".") {
					if (dotCount == 1) { break; };
					dotCount++;
					numStr += ".";
					this->advance();
				}
				else { numStr += this->currentChar; this->advance(); }
			};
			// See lib/token.hpp:18
			return (dotCount == 0) ? Token(TT_INT, numStr) : Token(TT_FLOAT, numStr);
		}

		// Function to turn the input into tokens
		tokenErrorPair makeTokens(){
			// Declare vector of Tokens
			tokenErrorPair tokensAndError;

			// Loop through our input text
			while (this->currentChar != NULL_STR){
				// Decide what token it is from the input
				// Ignore spaces or tabs
				if (this->currentChar == " " || this->currentChar == "\t") {
					this->advance();
				}
				else if (isDotOrDigit(this->currentChar)) {
					tokensAndError.tokens.push_back(this->makeNumber());
				}
				else if (this->currentChar == "+"){
					tokensAndError.tokens.push_back(Token(TT_PLUS));
					this->advance();
				}
				else if (this->currentChar == "-"){
					tokensAndError.tokens.push_back(Token(TT_MINUS));
					this->advance();
				}
				else if (this->currentChar == "*"){
					tokensAndError.tokens.push_back(Token(TT_MUL));
					this->advance();
				}
				else if (this->currentChar == "/"){
					tokensAndError.tokens.push_back(Token(TT_DIV));
					this->advance();
				}
				else if (this->currentChar == "("){
					tokensAndError.tokens.push_back(Token(TT_LPAREN));
					this->advance();
				}
				else if (this->currentChar == ")"){
					tokensAndError.tokens.push_back(Token(TT_RPAREN));
					this->advance();
				}
				else {
					tokensAndError.tokens = {};
					Position posStart = this->pos.copy();
					std::string cChar = this->currentChar;
					this->advance();
					tokensAndError.error = IllegalCharError(
						posStart,
						this->pos,
						cChar
					);
					return tokensAndError;
				}
			};
			return tokensAndError;
		}
};
// this is a comment to make make think i changed something

// this is a comment to make make think i changed something
