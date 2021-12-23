#include <vector>
#include <algorithm>
#include <string>

#include "consts.hpp"
#include "token.hpp"
#include "errors.hpp"


bool isDotOrDigit(int c){
	return (
		// Between 48 (0) and 57 (9) or 46 (.)
		((47 < c) && (c < 58)) || (c == 46)
	);
};
bool isDotOrDigit(std::string c){
	// Call the above method with ASCII value of c
	// https://www.geeksforgeeks.org/function-overloading-c/
	return isDotOrDigit(c[0]);
};

// Surround input in single quotes
std::string quote(std::string x){
	return "'" + x + "'";
};

typedef struct tokenErrorPair {
	std::vector<Token> tokens;
	Error error;
} tokenErrorPair;

template <typename T>
bool elemInVec (std::vector<T> vec, T elem){
	return std::find(vec.begin(), vec.end(), elem) != vec.end();
};

// this is a comment to make make think i changed something
