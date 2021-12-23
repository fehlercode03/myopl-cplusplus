#ifdef HAVE_SYS_FMT
#	include <fmt/core.h>
#else
#	include "fmt/include/core.h"
#endif

#include <string>

#include "token.hpp"

class Node {
	public:
		//auto leftNode, rightNode;
		//Token opTok, tok;
		Node(){};
		std::string asString(){ return "Node()"; };
};

class NumberNode: public Node {
	public:
		Token tok;

		NumberNode(){};

		NumberNode(Token t){
			tok = t;
		};

		// lib/token.hpp:15
		std::string asString() {
			return this->tok.asString();
		}
};

class BinOpNode: public Node {
	public:
		Node* leftNode;
		Node* rightNode;
		Token opTok;

		BinOpNode();

		BinOpNode(Node* lN, Token oT, Node* rN){
			leftNode = lN;
			rightNode = rN;
			opTok = oT;
		};
		std::string asString() {
			return fmt::format(
				"({0:s}, {1:s}, {2:s})",
				this->leftNode->asString(),
				this->opTok.asString(),
				this->rightNode->asString()
			);
		}
};// this is a comment to make make think i changed something
