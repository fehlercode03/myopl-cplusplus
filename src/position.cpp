#include <string>

typedef struct PositionArgs {
	int idx = 0, ln = 0, col = 0;
	std::string fileName, fileText;
} PositionArgs;

class Position {
	public:
		int idx = 0, ln = 0, col = 0;
		std::string fileName, fileText;
		
		Position(){};

		Position(PositionArgs pA){
			idx = pA.idx;
			ln = pA.ln;
			col = pA.col;
			fileName = pA.fileName;
			fileText = pA.fileText;
		};

		int advance(std::string currentChar){
			this->idx++;
			//this->ln++;

			if (currentChar == "\n"){
				this->ln++;
				this->col = 0;
			};

			return 0;
		};

		Position copy(){
			return Position({
				.idx = this->idx,
				.ln = this->ln,
				.col = this->col,
				.fileName = this->fileName,
				.fileText = this->fileText
			});
		}
};
// this is a comment to make make think i changed something src/utils.cpp
