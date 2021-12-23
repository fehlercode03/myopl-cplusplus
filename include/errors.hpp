#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

#include "consts.hpp"
#include "position.hpp"

class Error {
	public:
		Position posEnd, posStart;
		std::string name, details;
		bool colour = true;
		Error();
		Error(
			Position pS,
			Position pE,
			std::string n = NULL_STR,
			std::string d = NULL_STR,
			bool c = true
		);
		virtual std::string asString();

};

class IllegalCharError: public Error {
	public:
		Position posStart, posEnd;
		std::string name, details;
		bool colour = true;
		
		IllegalCharError();
		IllegalCharError(
			Position ps,
			Position pE,
			std::string d,
			bool c = true	
		);
		std::string asString();

};

#endif // ERROR_HPP_
