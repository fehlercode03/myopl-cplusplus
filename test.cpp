#include <fmt/core.h>
#include <iostream>
#include <memory>
//#include <cxxabi.h>
#include <string>
#include "src/token.cpp"
int main(int argc, char** argv){

	std::cout << tokenTypeToString(TT_RPAREN) << std::endl;
	return 0;
}