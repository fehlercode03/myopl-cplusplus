#ifdef HAVE_SYS_FMT
#	include <fmt/core.h>
#else
#	include "fmt/include/core.h"
#endif

#include <string>

#include "position.hpp"
#include "consts.hpp"

class Error {
	public:
		Position posStart, posEnd;
		std::string name, details;
		bool colour = true;
		
		Error(){};

		Error(
			Position pS,
			Position pE,
			std::string n = NULL_STR,
			std::string d = NULL_STR,
			bool c = true
		){
			posStart = pS;
			posEnd = pE;
			name = n;
			details = d;
			colour = c;
		};

		// lib/token.hpp:15
		std::string asString() {
			std::string result = fmt::format(
				"{0:s}: '{1:s}'\nFile '{2:s}', line {3:d}",
				this->name,
				this->details,
				this->posStart.fileName,
				this->posStart.ln + 1
			);
			return (this->colour) ?
			"\x1b[31;1m" + result + "\x1b[0m":
			result;
		}

};

class IllegalCharError: public Error {
	public:
		Position posStart, posEnd;
		std::string name, details;
		bool colour = true;
		
		IllegalCharError();
		IllegalCharError(
			Position pS,
			Position pE,
			std::string d,
			bool c = true	
		): Error(pS, pE, "IllegalCharError", d, c){};
		std::string asString();

};

// this is a comment