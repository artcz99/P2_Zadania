//Artur Czarnik, Zestaw 6

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matrix {
    unsigned short size; //size*size
    int** matrix;
};

void PrintMatrix (struct Matrix matrix) {
    int i, j;
    for(i = 0; i < matrix.size; i++) {
        for(j = 0; j < matrix.size; j++) {
            printf("%d ", *(*(matrix.matrix + i) + j));
        }
        printf("\n");
    }
}

struct Matrix CreateMatrix(unsigned short size) {
    struct Matrix matrix;
    matrix.size = size;
    matrix.matrix = (int **) malloc(size * sizeof(int *));
    int i, j;
    for(i = 0; i < matrix.size; i++) {
        int *row = (int *) malloc(size * sizeof(int));
        for(j = 0; j < matrix.size; j++) {
            int val;
            scanf("%d", &val);
            *(row + j) = val;
        }
        *(matrix.matrix + i) = row;
    }
    return matrix;
}

struct Matrix CreateEmptyMatrix(int size) { //creates matrix size*size with 0's
    struct Matrix C;
    C.size = size;
    C.matrix = (int **) malloc(size * sizeof(int *));
    int i;
    for(i = 0; i < size; i++) {
        int *row = (int *) calloc(size, sizeof(int));
        *(C.matrix + i) = row;
    }
    return C;
}

struct Matrix Addition(struct Matrix A, struct Matrix B) {
    struct Matrix C = CreateEmptyMatrix(A.size);
    int i, j;
    for(i = 0; i < A.size; i++) {
        for(j = 0; j < A.size; j++) {
            *(*(C.matrix + i) + j) = *(*(A.matrix + i) + j) + *(*(B.matrix + i) + j);
        }
    }
    return C;
}

struct Matrix Subtraction(struct Matrix A, struct Matrix B) {
    struct Matrix C = CreateEmptyMatrix(A.size);
    int i, j;
    for(i = 0; i < B.size; i++) {
        for(j = 0; j < B.size; j++) {
            *(*(C.matrix + i) + j) = *(*(A.matrix + i) + j) - *(*(B.matrix + i) + j);
        }
    }
    return C;
}

struct Matrix Multipliaction(struct Matrix A, struct Matrix B) {
    struct Matrix C = CreateEmptyMatrix(A.size);
    int i, j, k;
    for(i = 0; i < B.size; i++) {
        for(j = 0; j < B.size; j++) {
            for(k = 0; k < B.size; k++) {
                *(*(C.matrix + i) + j) += *(*(A.matrix + i) + k) * *(*(B.matrix + k) + j);
            }
        }
    }
    return C;
}

struct Matrix ScalarMultiplication(int scalar, struct Matrix A) {
    struct Matrix C = CreateEmptyMatrix(A.size);
    int i, j;
    for(i = 0; i < A.size; i++) {
        for(j = 0; j < A.size; j++) {
            *(*(C.matrix + i) + j) = *(*(A.matrix + i) + j) * scalar;
        }
    }
    return C;
}

bool IsEqual(struct Matrix A, struct Matrix B) {
    int i, j;
    for(i = 0; i < A.size; i++) {
        for(j = 0; j < A.size; j++) {
            if(*(*(A.matrix + i) + j) != *(*(B.matrix + i) + j)) return false;
        }
    }
    return true;
}

int Determinant(struct Matrix A) { //works only for 1x1, 2x2, 3x3 matrices
    int i, j;
    if(A.size == 1)
        return **A.matrix;
    else if(A.size == 2)
        return *(*(A.matrix + 0) + 0) * *(*(A.matrix + 1) + 1) - *(*(A.matrix + 0) + 1) * *(*(A.matrix + 1) + 0);
    else if(A.size == 3) {
        int temp_1 = *(*(A.matrix + 0) + 0) * *(*(A.matrix + 1) + 1) * *(*(A.matrix + 2) + 2);
        temp_1 += *(*(A.matrix + 1) + 0) * *(*(A.matrix + 2) + 1) * *(*(A.matrix + 0) + 2);
        temp_1 += *(*(A.matrix + 2) + 0) * *(*(A.matrix + 0) + 1) * *(*(A.matrix + 1) + 2);
        temp_1 -= *(*(A.matrix + 0) + 2) * *(*(A.matrix + 1) + 1) * *(*(A.matrix + 2) + 0);
        temp_1 -= *(*(A.matrix + 1) + 2) * *(*(A.matrix + 2) + 1) * *(*(A.matrix + 0) + 0);
        temp_1 -= *(*(A.matrix + 2) + 2) * *(*(A.matrix + 0) + 1) * *(*(A.matrix + 1) + 0);
        return temp_1;
    } else
        return -1;
}

struct Matrix Transpose(struct Matrix A) {
    struct Matrix C = CreateEmptyMatrix(A.size);
    int i, j;
    for(i = 0; i < (A.size - 1); i++) {
        for(j = 1 + i; j < (A.size); j++) {
            *(*(C.matrix + i) + j) = *(*(A.matrix + j) + i);
            *(*(C.matrix + j) + i) = *(*(A.matrix + i) + j);
        }
    }
    for(i = 0; i < (A.size); i++) {
        *(*(C.matrix + i) + i) = *(*(A.matrix + i) + i);
    }
    return C;
}

bool IsMatrixUpperTriangular(struct Matrix A) {
    int i, j;
    for(i = 0; i < (A.size - 1); i++) {
        for(j = 1 + i; j < (A.size); j++) {
            if(*(*(A.matrix + i) + j) != 0) return false;
        }
    }
    return true;
}

bool IsMatrixLowerTriangular(struct Matrix A) {
    int i, j;
    for(i = 0; i < (A.size - 1); i++) {
        for(j = 1 + i; j < (A.size); j++) {
            if(*(*(A.matrix + j) + i) != 0) return false;
        }
    }
    return true;
}

int Trace(struct Matrix A) {
    int temp = 0;
    int i;
    for(i = 0; i < A.size; i++) {
        temp += *(*(A.matrix + i) + i);
    }
    return temp;
}

void Delete(struct Matrix A) {
    if(A.matrix == NULL) return;
    int i;
    for(i = 0; i < A.size; i++) {
        free(*(A.matrix + i));
    }
    free(A.matrix);
    A.matrix = NULL;
}

bool IsSymmetrical(struct Matrix A) {
    struct Matrix C = Transpose(A);
    bool tmp = IsEqual(C, A);
    Delete(C);
    return tmp;
}

bool IsIdentity(struct Matrix A) {
    return IsMatrixLowerTriangular(A) && IsMatrixUpperTriangular(A) && (Trace(A) == A.size);
}

bool IsSparse(struct Matrix A) {
    int val = 0;
    int i, j;
    for(i = 0; i < (A.size - 1); i++) {
        for(j = 1 + i; j < (A.size); j++) {
            if(*(*(A.matrix + j) + i) == 0) val++;
        }
    }
    return val > A.size * A.size;
}

int main() { //input: size elementsOfMatrixA  elementsOfMatrixB
/* example input
5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
-1 -2 -3 -4 -5
-6 -7 -8 -9 -10
-11 -12 -13 -14 -15
-16 -17 -18 -19 -20
-21 -22 -23 -24 -25
 */

/* example input
3
5 9 2
2 0 3
4 9 2
5 9 2
2 0 3
4 9 2
 */
    int size;
    scanf("%d", &size);
    struct Matrix A = CreateMatrix(size);
    struct Matrix B = CreateMatrix(size);
    struct Matrix C;

    printf("\nA:\n");
    PrintMatrix(A);
    printf("\nB:\n");
    PrintMatrix(B);

    //1. dodawanie dwóch macierzy
    printf("\nA + B:\n");
    C = Addition(A, B);
    PrintMatrix(C);
    Delete(C);

    //2. odejmowanie dwóch macierzy
    printf("\nA - B:\n");
    C = Subtraction(A, B);
    PrintMatrix(C);
    Delete(C);

    //3. mnożenie dwóch macierzy
    printf("\nA * B:\n");
    C = Multipliaction(A, B);
    PrintMatrix(C);
    Delete(C);

    //4. mnożenie przez skalar
    int val = 4;
    printf("\n%d * A:\n", val);
    C = ScalarMultiplication(4, A);
    PrintMatrix(C);
    Delete(C);

    //5. sprawdzanie czy dwie macierze są równe
    printf("\nCzy (A == B)?:\n");
    printf("%s\n", IsEqual(A, B)?"true":"false");

    //6. obliczanie wyznacznika
    printf("\ndet(A):\n");
    printf("%d\n", Determinant(A));

    //7. transpozycja
    printf("\nA^T:\n");
    C = Transpose(A);
    PrintMatrix(C);
    Delete(C);

    //8. obliczanie sumy na głównej przekątnej
    printf("\ntrA (ślad macierzy A):\n");
    printf("%d\n", Trace(A));

    //9. prawdzanie czy macierz jest ’górna trójkątna’
    printf("\nCzy A - górna trójkątna?:\n");
    printf("%s\n", IsMatrixUpperTriangular(A)?"true":"false");

    //10. sprawdzanie czy macierz jest ’dolna trójkątna’
    printf("\nCzy A - dolna trójkątna?:\n");
    printf("%s\n", IsMatrixLowerTriangular(A)?"true":"false");

    //11. sprawdzanie czy macierz jest ’identycznością’
    printf("\nCzy A - identyczność?:\n");
    printf("%s\n", IsIdentity(A)?"true":"false");

    //12. sprawdzanie czy macierz jest ’rzadka’
    printf("\nCzy A - rzadka?:\n");
    printf("%s\n", IsSparse(A)?"true":"false");

    //13. sprawdzanie czy macierz jest ’symetryczna’
    printf("\nCzy A - symetryczna?:\n");
    printf("%s\n", IsSymmetrical(A)?"true":"false");

    Delete(A);
    Delete(B);

    return 0;
}