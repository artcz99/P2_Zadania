//Artur Czarnik, Zestaw 5_3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

void Task_11(void) {
    int size;
    printf("Podaj rozmiar tablicy\n");
    scanf("%d", &size);
    int *array;
    array = (int *) malloc(size * sizeof(int));

    int i, j;
    for (i = 0; i < size; i++) {
        *(array + i) = rand() % 100;
    }

    int *temp_arr = (int *) malloc(0);
    int temp_size = 0;
    printf("Tablica z duplikatami:");
    for (i = 0; i < size; i++) {
        printf(" %d", *(array + i));
    }
    printf("\n");
    printf("Rozmiar tablicy: %d\n", size);
    printf("Tablica bez duplikatów:");
    for (i = 0; i < size; i++) {
        bool flag = true;
        for (j = 0; j < temp_size; j++) {
            if (*(array + i) == *(temp_arr + j)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf(" %d", *(array + i));
            temp_size++;
            temp_arr = (int *) realloc(temp_arr, temp_size * (sizeof(int)));
            *(temp_arr + temp_size - 1) = *(array + i);
        }
    }
    printf("\n");
    free(temp_arr);
    free(array);
}

void Task_12() {
    int **array;
    int h;
    int w;
    scanf("%d", &h);
    scanf("%d", &w);
    array = (int **) malloc(h * sizeof(int *));
    int i, j, k;
    for (i = 0; i < h; i++) {
        *(array + i) = (int *) malloc(w * sizeof(int));
        for (j = 0; j < w; j++) {
            *(*(array + i) + j) = rand() % 100;
        }
    }

    int temp;
    for (i = 0; i < h; i++) { //bubble sort
        for (k = 0; k < (w - 1); k++)
            for (j = 0; j < (w - 1 - k); j++) {
                if (*(*(array + i) + j) > *(*(array + i) + j + 1)) {
                    temp = *(*(array + i) + j);
                    *(*(array + i) + j) = *(*(array + i) + j + 1);
                    *(*(array + i) + j + 1) = temp;
                }
            }
    }

    double *deviation = (double *) malloc(h * sizeof(double));

    for (i = 0; i < h; i++) {
        double temp_avar = 0;
        for (j = 0; j < w; j++) {
            temp_avar += *(*(array + i) + j);
        }
        temp_avar /= w;
        double temp_deviat = 0;
        for (j = 0; j < w; j++) {
            temp_deviat += pow(*(*(array + i) + j) - temp_avar, 2);
        }
        *(deviation + i) = sqrt(temp_deviat / w);
    }
    printf("\n");
    printf("Wariancja wierszy: ");
    for (i = 0; i < h; i++) {
        printf("%f ", *(deviation + i));
    }
    printf("\nTablica 2D z posortowanymi kolumnami\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }

    double tempd;
    for (k = 0; k < (h - 1); k++)
        for (j = 0; j < (h - 1 - k); j++) {
            if (*(deviation + j) > *(deviation + j + 1)) {
                tempd = *(deviation + j);
                *(deviation + j) = *(deviation + j + 1);
                *(deviation + j + 1) = tempd;
                int *tempp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = tempp;
            }
        }
    printf("Tablica 2D z posortowanymi wierszami wzgledem odchylenia standardowego\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < h; i++) {
        free(*(array + i));
    }
    if (array != NULL) {
        free(array);
    }
    if (deviation != NULL)
        free(deviation);
}

void Task_13() {
    int **array;
    int h;
    int w;
    scanf("%d", &h);
    scanf("%d", &w);
    array = (int **) malloc(h * sizeof(int *));
    int i, j;
    for (i = 0; i < h; i++) {
        *(array + i) = (int *) malloc(w * sizeof(int));
        for (j = 0; j < w; j++) {
            *(*(array + i) + j) = rand() % 100;
        }
    }
    printf("Tablica 2D:\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < h; i++) {
        free(*(array + i));
    }
    if (array != NULL) {
        free(array);
        printf("Pamięć zwolniona!");
    }
}

int main(void) {
/* Example input
5
5 6
4 5

 */
    srand(time(NULL));
    Task_11();
    Task_12();
    Task_13();

    return 0;
}