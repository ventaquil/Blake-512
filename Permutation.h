#pragma once
#include<cstdlib>

class Permutation {
    public:
        static int* ReturnPermutation(int);
        static int ReturnPermutationValue(int, int);
    private:
        static int* CreatePermutation(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};