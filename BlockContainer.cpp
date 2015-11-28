#include"BlocksContainer.h"

int BlocksContainer::GetLength(void) {
	return this->Length;
}

Block* BlocksContainer::GetNBlock(int N) {
	if ((N >= this->Length) || (N < 0)) {
		return NULL;
	}
	else {
		return this->Blocks[N];
	}
}

BlocksContainer::BlocksContainer(Block** Blocks, int Elements, int Padding) {
	this->Blocks = Blocks;
	this->Length = Elements;
	this->Padding = Padding;
}

int BlocksContainer::GetPadding(void){
	return this->Padding;
}
