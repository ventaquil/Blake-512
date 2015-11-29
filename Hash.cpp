#include"Hash.h"

std::string Hash::H[8] = {
    "6A09E667F3BCC908",
    "BB67AE8584CAA73B",
    "3C6EF372FE94F82B",
    "A54FF53A5F1D36F1",
    "510E527FADE682D1",
    "9B05688C2B3E6C1F",
    "1F83D9ABFB41BD6B",
    "5BE0CD19137E2179"
};
const std::string Hash::C[16] = {
    "243F6A8885A308D3",
    "13198A2E03707344",
    "A4093822299F31D0",
    "082EFA98EC4E6C89",
    "452821E638D01377",
    "BE5466CF34E90C6C",
    "C0AC29B7C97C50DD",
    "3F84D5B5B5470917",
    "9216D5D98979FB1B",
    "D1310BA698DFB5AC",
    "2FFD72DBD01ADFB7",
    "B8E1AFED6A267E96",
    "BA7C9045F12C7F99",
    "24A19947B3916CF7",
    "0801F2E2858EFC16",
    "636920D871574E69"
};

std::string Hash::S[4] = {
    "",
    "",
    "",
    ""
};

std::string Hash::T[2] = {
    "",
    ""
};

Block* Hash::WorkingBlock = NULL;

int Hash::Gi = 0;
int Hash::R = 0;

std::string TH(std::string M){
    return Basics::ToHex(M);
}

void Hash::Make(BlocksContainer* Container) {
    std::string V[16];
    for (int a = 0; a < 8; a++) {
        Hash::H[a] = Basics::Translate(Hash::H[a]);
    }

    int Padding = Container->GetPadding();
    unsigned int Encrypted = 0;

    for (int a = 0, b = Container->GetLength(); a < b; a++){
        Hash::T[0] = "";

        if (Padding <= 1024){
            if ((a + 1) < b){
                Encrypted += 1024;
            }
            else{
                Encrypted += 1024 - Padding;
            }
            Hash::T[0].push_back((char)Encrypted);
        }
        else{
            if (ceil((Encrypted + Padding) / 8) > b){
                Hash::T[0].push_back((char)Encrypted);
            }
            else{
                Hash::T[0].push_back((char)0);
            }
        }

        for (int c = 0; c < 8; c++) {
            V[c] = Hash::H[c];
        }
        for (int c = 0; c < 4; c++) {
            V[8 + c] = Hash::Xor(Basics::Translate(Hash::S[c]), Basics::Translate(Hash::C[c]));
        }
        for (int c = 0; c < 2; c++) {
            V[12 + c] = Hash::Xor(Hash::T[0], Basics::Translate(Hash::C[4 + c]));
        }
        for (int c = 0; c < 2; c++) {
            V[14 + c] = Hash::Xor(Hash::T[1], Basics::Translate(Hash::C[6 + c]));
        }

        Hash::WorkingBlock = Container->GetNBlock(a);

        for (Hash::R = 0; Hash::R < 16; Hash::R++){
            Hash::Gi = 0;

            Hash::G(&V[0], &V[4], &V[8], &V[12]);
            Hash::G(&V[1], &V[5], &V[9], &V[13]);
            Hash::G(&V[2], &V[6], &V[10], &V[14]);
            Hash::G(&V[3], &V[7], &V[11], &V[15]);
            Hash::G(&V[0], &V[5], &V[10], &V[15]);
            Hash::G(&V[1], &V[6], &V[11], &V[12]);
            Hash::G(&V[2], &V[7], &V[8], &V[13]);
            Hash::G(&V[3], &V[4], &V[9], &V[14]);
        }

        for (int a = 0; a < 8; a++) {
            Hash::H[a] = Hash::Xor(Hash::Xor(Hash::H[a], Hash::S[a % 4]), Hash::Xor(V[a], V[a + 8]));
        }
    }

    for (int a = 0; a < 8; a++){
        std::cout << Basics::ToHex(Hash::H[a]);
    }
}

void Hash::G(std::string* A, std::string* B, std::string* C, std::string* D) {
    std::string A_=*A, B_=*B, C_=*C, D_=*D;

    A_ = Hash::Add(
        A_,
        Hash::Add(B_,
            Hash::Xor(
                WorkingBlock->Get64b(Permutation::ReturnPermutationValue(Hash::R % 10, 2 * Hash::Gi)),
                Basics::Translate(Hash::C[Permutation::ReturnPermutationValue(Hash::R % 10, (2 * Hash::Gi) + 1)])
            )
        )
    );
    D_ = Hash::RotateRight(
        Hash::Xor(D_, A_),
        32
        );
    C_ = Hash::Add(C_, D_);
    B_ = Hash::RotateRight(
        Hash::Xor(B_, C_),
        25
        );
    A_ = Hash::Add(
        A_,
        Hash::Add(B_,
        Hash::Xor(
            WorkingBlock->Get64b(Permutation::ReturnPermutationValue(Hash::R % 10, (2 * Hash::Gi) + 1)),
            Basics::Translate(Hash::C[Permutation::ReturnPermutationValue(Hash::R % 10, 2 * Hash::Gi)])
        )
        )
    );
    D_ = Hash::RotateRight(
        Hash::Xor(D_, A_),
        16
    );
    C_ = Hash::Add(C_, D_);
    B_ = Hash::RotateRight(
        Hash::Xor(B_, C_),
        11
    );

    *A = A_;
    *B = B_;
    *C = C_;
    *D = D_;

    Hash::Gi++;
}

std::string Hash::Add(std::string FirstString, std::string SecondString) {
    FirstString = Basics::ToHex(FirstString);
    SecondString = Basics::ToHex(SecondString);
    unsigned long long FirstNum = std::strtoull(FirstString.c_str(), NULL, 16);
    unsigned long long SecondNum = std::strtoull(SecondString.c_str(), NULL, 16);
    unsigned long long Num = FirstNum + SecondNum;

    std::stringstream Stream;
    Stream << std::hex << Num;
    return Basics::Translate(Stream.str());
}

std::string Hash::Xor(std::string FirstString, std::string SecondString) {
    FirstString = Basics::ToHex(FirstString);
    SecondString = Basics::ToHex(SecondString);
    unsigned long long FirstNum = std::strtoull(FirstString.c_str(), NULL, 16);
    unsigned long long SecondNum = std::strtoull(SecondString.c_str(), NULL, 16);
    unsigned long long Num = FirstNum ^ SecondNum;

    std::stringstream Stream;
    Stream << std::hex << Num;
    return Basics::Translate(Stream.str());
}

std::string Hash::RotateRight(std::string Message, unsigned int Value){
    Message = Basics::ToHex(Message);
    int FirstPointer, SecondPointer;
    unsigned long long Num = std::strtoull(Message.c_str(), NULL, 16);
    Value %= 64;
    Num = (Num >> Value) | (Num << (64 - Value));

    std::stringstream Stream;
    Stream << std::hex << Num;
    return Basics::Translate(Stream.str());
}
