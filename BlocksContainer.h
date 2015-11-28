#pragma once
#include<cstdlib>
#include<iostream>

class Block;

class BlocksContainer {
	public:
		int GetLength(void);
		Block* GetNBlock(int);
		BlocksContainer(Block**, int, int);
		int GetPadding(void);
	protected:
		Block** Blocks;
		int Length;
		int Padding;
};
