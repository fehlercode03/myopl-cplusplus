#include <iostream>

#include "include/lexer.hpp"
#include "include/token.hpp"
#include "include/errors.hpp"
#include "include/consts.hpp"
#include "include/parser.hpp"
#include "include/nodes.hpp"

tokenErrorPair run(std::string fn, std::string text){
	Lexer lexer = Lexer(fn , text);
	tokenErrorPair tokensAndError = lexer.makeTokens();

	Parser parser = Parser(tokensAndError.tokens);
	Node* ast = parser.parse();
	std::cout << ast->asString() << std::endl;
	return tokensAndError;
};

int shell() {
	while (1) {
		// Declare input and read
		std::string inp;
		std::cout << "basic> ";
		std::getline(std::cin, inp);
		// Create the lexer and pass the input
		// Make a vector of the tokens
		tokenErrorPair tokensAndError = run("<stdin>", inp);
		if (tokensAndError.error.name != NULL_STR){
			std::cerr << tokensAndError.error.asString() << std::endl;
			continue;
		} else {
			// Loop through and print them
			std::cout << "[";
			for (int i = 0; i < tokensAndError.tokens.size(); i++) {
				std::cout << tokensAndError.tokens[i].asString() << ", ";
			};
			std::cout << "]" << std::endl;
			}
	}
}

int main(int argc, char **argv) {
	shell();
	return 0;
}
