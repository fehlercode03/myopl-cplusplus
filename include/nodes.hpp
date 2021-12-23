#ifndef NODES_HPP_
#define NODES_HPP_

#include <string>
#include <memory>

#include "token.hpp"

class Node {
	public:
		Node();
		virtual ~Node(){};
		virtual std::string asString();
};

class NumberNode: public Node {
	public:
		Token tok;

		NumberNode();
		NumberNode(Token t);

		std::string asString();
};

class BinOpNode {
	public:
		std::unique_ptr<Node> leftNode, rightNode;
		Token opTok;

		BinOpNode();
		BinOpNode(
			std::unique_ptr<Node> lN,
			Token oT,
			std::unique_ptr<Node> rN
		);
		std::string asString();
};

#endif // NODES_HPP_
