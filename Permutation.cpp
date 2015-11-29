#include"Permutation.h"

int* Permutation::ReturnPermutation(int Row){
    if ((Row >= 0) && (Row <= 9)){
        int* Permutation = NULL;
        switch (Row){
            case 0:
                Permutation = Permutation::CreatePermutation(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
                break;
            case 1:
                Permutation = Permutation::CreatePermutation(14, 10, 4, 8, 9, 15, 13, 6, 1, 12, 0, 2, 11, 7, 5, 3);
                break;
            case 2:
                Permutation = Permutation::CreatePermutation(11, 8, 12, 0, 5, 2, 15, 13, 10, 14, 3, 6, 7, 1, 9, 4);
                break;
            case 3:
                Permutation = Permutation::CreatePermutation(7, 9, 3, 1, 13, 12, 11, 14, 2, 6, 5, 10, 4, 0, 15, 8);
                break;
            case 4:
                Permutation = Permutation::CreatePermutation(9, 0, 5, 7, 2, 4, 10, 15, 14, 1, 11, 12, 6, 8, 3, 13);
                break;
            case 5:
                Permutation = Permutation::CreatePermutation(2, 12, 6, 10, 0, 11, 8, 3, 4, 13, 7, 5, 15, 14, 1, 9);
                break;
            case 6:
                Permutation = Permutation::CreatePermutation(12, 5, 1, 15, 14, 13, 4, 10, 0, 7, 6, 3, 9, 2, 8, 11);
                break;
            case 7:
                Permutation = Permutation::CreatePermutation(13, 11, 7, 14, 12, 1, 3, 9, 5, 0, 15, 4, 8, 6, 2, 10);
                break;
            case 8:
                Permutation = Permutation::CreatePermutation(6, 15, 14, 9, 11, 3, 0, 8, 12, 2, 13, 7, 1, 4, 10, 5);
                break;
            case 9:
                Permutation = Permutation::CreatePermutation(10, 2, 8, 4, 7, 6, 1, 5, 15, 11, 9, 14, 3, 12, 13, 0);
                break;
        }
        return Permutation;
    }
    else{
        return NULL;
    }
}

int Permutation::ReturnPermutationValue(int Row, int Column){
    int* Permutation = Permutation::ReturnPermutation(Row);
    if ((Permutation != NULL) && (Column >= 0) && (Column < 16)){
        return Permutation[Column];
    }
    else{
        return 0;
    }
}

int* Permutation::CreatePermutation(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p){
    int* Permutation = new int[16];
    Permutation[0] = a;
    Permutation[1] = b;
    Permutation[2] = c;
    Permutation[3] = d;
    Permutation[4] = e;
    Permutation[5] = f;
    Permutation[6] = g;
    Permutation[7] = h;
    Permutation[8] = i;
    Permutation[9] = j;
    Permutation[10] = k;
    Permutation[11] = l;
    Permutation[12] = m;
    Permutation[13] = n;
    Permutation[14] = o;
    Permutation[15] = p;
    return Permutation;
}
