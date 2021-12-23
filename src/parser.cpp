#include <vector>
#include <string>
#include <memory>

#include "token.hpp"
#include "nodes.hpp"
#include "consts.hpp"
#include "utils.hpp"

class Parser {
	public:
		std::vector<Token> tokens;
		Token currentToken;
		int tok_idx = -1;

		Parser();
		Parser(std::vector<Token> t){
			tokens = t;
			this->advance();
		};

		Token advance(){
			this->tok_idx++;

			if (this->tok_idx < this->tokens.size()){
				this->currentToken = this->tokens[this->tok_idx];
			}
			return this->currentToken;
		};


		std::unique_ptr<NumberNode> factor(){
			Token tok = this->currentToken;

			if (elemInVec({TT_INT, TT_FLOAT}, tok.type)){
				this->advance();
				return std::make_unique<NumberNode>(new NumberNode(tok));
			} else {
				return std::make_unique<NumberNode>(new NumberNode());
			};
		};

		std::unique_ptr<Node> binop(std::string funcName, std::vector<TokenType> ops){
			std::unique_ptr<Node> left = (funcName == "factor") ? this->factor() : this->term();
			Token opTok;

			while (elemInVec(ops, this->currentToken.type)){
				opTok = this->currentToken;
				this->advance();
				std::unique_ptr<Node> right = (funcName == "factor") ? this->factor() : this->term();

				// BinOpNode _left(left, opTok, right);
				left = std::make_unique<BinOpNode>(
					new BinOpNode(std::move(left), opTok, std::move(right))
				);
			};
			return left;
			
		};

		std::unique_ptr<Node> term(){
			return this->binop("factor", {TT_MUL, TT_DIV});
		};

		std::unique_ptr<Node> expr(){
			return this->binop("term", {TT_PLUS, TT_MINUS});
		};

		std::unique_ptr<Node> parse(){
			return this->expr();
		};

};
// this is a comment to make make think i changed something
