#include<iostream>
#include<string>
#include"Basics.h"
#include"Block.h"
#include"Hash.h"
#include"Permutation.h"

void ShowContainerBlocks(BlocksContainer*);

int main(int args, char* argv[]) {
	std::string Message;
	if (args > 1){
		Message = (std::string)argv[1];
	}
	else{
		Message = "";
	}

	BlocksContainer* Container = Block::CreateBlocks(Basics::Translate(Message));

    Hash::Make(Container);

	return 0;
}

void ShowContainerBlocks(BlocksContainer* Container) {
	int ContainerLength = Container->GetLength();
	std::cout << "Container Blocks: " << ContainerLength << std::endl;
	for (int a = 0; a < ContainerLength; a++) {
		std::cout << "Block " << a + 1 << " -> " << std::endl;
		for (int b = 0; b < 16; b++) {
			std::cout << "       " << b + 1 << " " << Basics::ToHex(Container->GetNBlock(a)->Get64b(b)) << std::endl;
		}
	}
}
