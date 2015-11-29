#include"Block.h"

BlocksContainer* Block::CreateBlocks(std::string Message) {
    int Length = Message.length() * 8;
    int PaddingLength = 0;
    if (((Length % 1024) != 0) || (Length == 0)) {
        std::string Padding = Block::CreatePadding(Length);
        PaddingLength = Padding.length();
        for (int a = 0; a < PaddingLength; a += 8) {
            Message += (char)strtol(Padding.substr(a, 8).c_str(), NULL, 2);
        }
        Length += PaddingLength;
    }

    Length /= 8;

    Block** blocks = new Block*[Length];

    for (int a = 0; a < Length; a += 128) { // Get by 1024 bits (128 * 8 - 8 is char size)
        blocks[a / 128] = new Block(Message.substr(a, 128));
    }

    return new BlocksContainer(blocks, ceil(Length / 128.), PaddingLength);
}

std::string Block::Get64b(int Number) {
    if ((Number >= 0) && (Number < 16)) {
        return this->BlockContent.substr(Number * 8, 8); // Get 64 bits
    }
    else {
        return "";
    }
}

std::string Block::CreatePadding(int Length) {
    int HowManyAdd = 1024 - (Length % 1024);
    std::string Binary;

    if (HowManyAdd < 130) {
        Binary = "1";
        for (int a = 2, b = HowManyAdd - 128 + 1024; a < b; a++) {
            Binary.append("0");
        }
        Binary.append("1");
    }
    else {
        Binary = "1";
        for (int a = 2, b = HowManyAdd - 128; a < b; a++) {
            Binary.append("0");
        }
        Binary.append("1");
    }

    Binary.append(std::bitset<128>(Length).to_string());

    return Binary;
}

Block::Block(std::string Message) {
    this->BlockContent = Message;
}

std::string Block::ReturnContent(void) {
    return this->BlockContent;
}
