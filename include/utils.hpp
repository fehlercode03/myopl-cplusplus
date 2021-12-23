#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include <string>

#include "consts.hpp"
#include "token.hpp"
#include "errors.hpp"


bool isDotOrDigit(int c);
bool isDotOrDigit(std::string c);

std::string quote(std::string x);

template <typename T>
bool elemInVec (std::vector<T> vec, T elem);

typedef struct tokenErrorPair {
	std::vector<Token> tokens;
	Error error;
} tokenErrorPair;

#endif // UTILS_HPP_
