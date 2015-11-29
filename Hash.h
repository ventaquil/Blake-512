#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
#include"Block.h"
#include"Basics.h"
#include"Permutation.h"

class Hash {
public:
    static void Make(BlocksContainer*);
    static std::string Xor(std::string, std::string);
    static std::string Add(std::string, std::string);
    static std::string RotateLeft(std::string, unsigned int);
    static std::string RotateRight(std::string, unsigned int);
    static unsigned char get8PreviousBits(std::string, unsigned int, unsigned int);
    static unsigned char get8NextBits(std::string, unsigned int, unsigned int);
private:
    static void G(std::string*, std::string*, std::string*, std::string*);
    static std::string S[4];
    static std::string T[2];
    static std::string H[8];
    static const std::string C[16];
    static Block* WorkingBlock;
    static int Gi;
    static int R;
};
