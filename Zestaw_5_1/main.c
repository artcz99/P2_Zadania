//Artur Czarnik, Zestaw 5_1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void read_number() {
    printf("\nPodaj dowolna dodatnia liczbe: \n");
    int val;
    scanf("%d", &val);

    char arr[][7] = {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
    };
    int SIZE = 11;
    char *s = (char *) malloc(10 * sizeof(char) + 1);
    sprintf(s, "%d", val);
    printf("Liczba wejsciowa: %s \n", s);

    int actual_size = 0;
    int i;
    for (i = 0; i < SIZE; i++) {
        if (*(s + i) >= 48 && *(s + i) <= 57) actual_size++;
    }

    for (i = 0; i < actual_size; i++) {
        char tmp = *(s + i);
        long int a = strtoul(&tmp, NULL, 10);
        printf("%s ", arr[a]);
    }
    printf("\n");
    free(s);
}

void rev_and_cap() {
    int SIZE = 32;
    char *str = (char *) malloc(SIZE * sizeof(char) + 1);
    scanf("%[^\n]", str);
    int i;

    int actual_size = 0;
    for (i = 0; i < SIZE; i++) {
        if (*(str + i) >= 97 && *(str + i) <= 122)
            *(str + i) = (char) ((int) *(str + i) - 32);
        if (*(str + i) >= 32 && *(str + i) <= 126) actual_size++;
    }

    for (i = 0; i < actual_size / 2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + actual_size - 1 - i);
        *(str + actual_size - 1 - i) = temp;
    }

    printf("%s\n", str);
    free(str);
}

void countzeros() {
    int value;
    scanf("%d",&value);
    char s[sizeof(long) * 8];
    sprintf(s, "%ld", value);
    unsigned short number_of_zeros = 0;
    unsigned int i;
    for (i = 0; i < sizeof(long) * 8; i++) {
        if (s[i] == '\0') break;
        if (s[i] == '0')
            number_of_zeros++;
    }
    printf("%d",number_of_zeros);
}

void map() {
    int SIZE = 26;
    char *str_s1 = (char *) malloc(SIZE * sizeof(char) + 1);
    char *str_s2 = (char *) malloc(SIZE * sizeof(char) + 1);
    strcpy(str_s1, "abcdefghijklmnopqrstuvwxyz");
    strcpy(str_s2, "zyxwvutsrqponmlkjihgfedcba");

    char *str_s3 = (char *) malloc(SIZE * sizeof(char) + 1);
    scanf("%s", str_s3);

    int actual_size = 0;
    int i;
    for (i = 0; i < SIZE; i++) {
        if (*(str_s3 + i) >= 97 && *(str_s3 + i) <= 122) actual_size++;
    }

    for (i = 0; i < actual_size; i++) {
        int j;
        for (j = 0; j < SIZE; j++)
            if (*(str_s1 + j) == *(str_s3 + i)) break;
        if (j == actual_size) continue;
        *(str_s3 + i) = *(str_s2 + j);
    }
    printf("%s", str_s3);
    free(str_s1);
    free(str_s2);
    free(str_s3);
}

int romanValue(char roman) {
    switch (roman) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
    }
}

void RomanArabic() {
    int SIZE = 10;
    char *str = (char *) malloc(SIZE * sizeof(char) + 1);
    scanf("%s", str);

    int i;
    int actual_size = 0;
    for (i = 0; i < SIZE; i++) {
        if (*(str + i) >= 32 && *(str + i) <= 126) actual_size++;
    }
    if (*str >= 48 && *str <= 57) { //arabic -> roman
        long int val = strtoul(str, NULL, 10);
        int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        char arr[][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        i = 12;
        while (val > 0) {
            int div = val / num[i];
            val = val % num[i];
            while (div--) {
                printf("%s", arr[i]) ;
            }
            i--;
        }
    } else { // roman -> arabic
        int val = 0;
        for (i = 0; i < actual_size; i++) {
            int v1 = romanValue(*(str + i));
            if (i + 1 < actual_size) {
                int v2 = romanValue(*(str + i + 1));
                if (v1 >= v2) {
                    val += v1;
                } else {
                    val += v2;
                    val -= v1;
                    i++;
                }
            } else {
                val += v1;
            }
        }
        printf("%d", val);
    }
    free(str);
}

int main(void) {
    //Zadanie 0
    printf("Podaj ciąg char'ow (maksymalna dl. 32): \n");
    rev_and_cap();

    //Zadanie 1
    printf("\nPodaj ciąg char'ow (bez duzych liter): \n");
    map();

    //Zadanie 2
    printf("\nPodaj liczbe dodatnia do odczytania: \n");
    read_number();

    //Zadanie 3
    printf("\nPodaj liczbe dodatnia do policzenia zer: \n");
    countzeros();

    //Zadane 4
    printf("\nPodaj liczbe rzymska lub arabska, aby ja zamienci: \n");
    RomanArabic();

    return 0;
}