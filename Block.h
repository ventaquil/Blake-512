#pragma once
#include<string>
#include<bitset>
#include<cmath>
#include"BlocksContainer.h"

class Block {
public:
	static BlocksContainer* CreateBlocks(std::string);
	static std::string CreatePadding(int);
	Block(std::string);
	std::string ReturnContent(void);
	std::string Get64b(int);
protected:
	std::string BlockContent;
};
