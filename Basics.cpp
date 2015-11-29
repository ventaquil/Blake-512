#include"Basics.h"

std::string Basics::Translate(std::string Message) {
    std::string Output;
    std::string Byte;
    unsigned char Chr;
    unsigned int MessageLength = Message.length();

    if ((MessageLength % 2) != 0){
        Message = "0" + Message;
    }

    for (unsigned int a = 0; a < MessageLength; a += 2) {
        Byte = Message.substr(a, 2);
        Chr = (char)(int)strtol(Byte.c_str(), NULL, 16);
        Output.push_back(Chr);
    }

    return Output;
}

std::string Basics::ToHex(std::string Message) {
    const char* HexSimbols = "0123456789ABCDEF";
    std::string Output;
    unsigned char Chr;
    for (int a = 0, b = Message.length(); a < b; a++) {
        Chr = Message[a];
        Output.push_back(HexSimbols[Chr >> 4]);
        Output.push_back(HexSimbols[Chr & 15]);
    }

    for (unsigned int a = Output.length(); a < 16; a++){
        Output.insert(0, "0");
    }

    return Output;
}
