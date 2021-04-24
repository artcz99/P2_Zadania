//Artur Czarnik, Zestaw 5_2

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void Task5(char *readfile_name, char *writefile_name) {
    FILE *ptr = fopen(readfile_name, "r");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", readfile_name);
        return;
    }
    double sum = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, ptr)) != -1) {
        int j = 0;
        while (*(line + j) != ' ') {
            j++;
        }
        j++;
        char *temp = malloc((read - j) * sizeof(char) + 1);
        int i = 0;
        while (*(line + j + i) != '\r' && *(line + j + i) != '\n') {
            char tm = *(line + j + i);
            if (*(line + j + i) == '\276') break;
            *(temp + i) = *(line + j + i);
            i++;
        }
        sum += strtod(temp, NULL);
        free(temp);
    }
    free(line);
    fclose(ptr);

    ptr = fopen(writefile_name, "a");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", writefile_name);
        return;
    }
    fprintf(ptr, " %f", sum);
    fclose(ptr);
}

void Task6(char *readfile_name, char *writefile_name) {
    FILE *ptr = fopen(readfile_name, "r");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", readfile_name);
        return;
    }
    double sum = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, ptr)) != -1) {
        int j = 0;
        while (*(line + j) != ':') {
            j++;
        }
        j++;
        j++;
        char *temp = malloc((read - j) * sizeof(char) + 1);
        int i = 0;
        while (*(line + j + i) != '\r' && *(line + j + i) != '\n') {
            char tm = *(line + j + i);
            if (*(line + j + i) == '\276') break;
            *(temp + i) = *(line + j + i);
            i++;
        }
        sum += strtod(temp, NULL);
        free(temp);
    }
    free(line);
    fclose(ptr);

    ptr = fopen(writefile_name, "a");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", writefile_name);
        return;
    }
    fprintf(ptr, " %f", sum);
    fclose(ptr);
}

void Task7(char *readfile_name, char *writefile_name) {
    FILE *ptr = fopen(readfile_name, "r");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", readfile_name);
        return;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int letters = 0;
    int min = INT32_MAX, max = -1;
    int total = 0;
    double avg = 0;

    int current_word = 0;

    while ((read = getline(&line, &len, ptr)) != -1) {
        int i = 0;
        while (*(line + i) != '\276' && *(line + i) != '\000' && *(line + i) != EOF) {
            char tmp = *(line + i);
            if ((*(line + i) >= 65 && *(line + i) <= 90) || (*(line + i) >= 97 && *(line + i) <= 122)) {
                letters++;
                current_word++;
            }
            if ((*(line + i) == '.') || (*(line + i) == ' ') || (*(line + i) == ',') || (*(line + i) == '\r') ||
                (*(line + i) == '\n')) {
                if (current_word == 0) {
                    i++;
                    continue;
                }
                if (current_word > max) max = current_word;
                if (current_word < min) min = current_word;
                if (min == 1) {
                    min = min;
                }
                avg += current_word;
                current_word = 0;
                total++;
            }
            if (*(line + i) == '\r' || *(line + i) == '\n') break;
            i++;
        }
    }
    free(line);
    fclose(ptr);
    ptr = fopen(writefile_name, "w");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", writefile_name);
        return;
    }
    avg /= total;
    fprintf(ptr, "{\n\taverage_length: %f;\n\tmax_length: %d;\n\tmin_length: %d;\n\tcounted_words: %d;\n}", avg, max,
            min, total);
    fclose(ptr);

}

char *get_name() {
    char *temp = (char *) malloc(100 * sizeof(char) + 1);
    scanf("%s", temp);
    int i;
    int actual_size = 0;
    for (i = 0; i < 100; i++) {
        if (*(temp + i) >= 32 && *(temp + i) <= 126) actual_size++;
    }
    char *return_char = (char *) malloc(actual_size * sizeof(char) + 1);
    for (i = 0; i < actual_size; i++) {
        *(return_char + i) = *(temp + i);
    }
    *(return_char + i) = '\0';
    free(temp);

    return return_char;
}

void tail(char *file, int val) {
    if(val <= 0) return;
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", file);
        return;
    }

    double sum = 0;
    char *line = NULL;
    size_t len = 0;
    int lines = 0;
    int ch;

    while (!feof(ptr)) {
        ch = fgetc(ptr);
        if (ch == '\n') {
            lines++;
        }
    }

    rewind(ptr);
    int i = 0;
    if(lines <= val) {
        while ((getline(&line, &len, ptr)) != -1) {
            printf("%s", line);
        }
    } else {
        while ((getline(&line, &len, ptr)) != -1) {
            if(i <= lines - val) {
                printf("%s", line);
            }
            i++;
        }
    }
    free(line);


    fclose(ptr);
}


void more(char *file) {
    FILE *ptr = fopen(file, "r");
    if (ptr == NULL) {
        printf("Nie udalo sie otworzyc pliku %s.\n", file);
        return;
    }

    double sum = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    getc(stdin);
    char a = getc(stdin);
    while(a != 'q' && a != '\27') {
        int val = a - '0';
        while(val != 0 && (read = (getline(&line, &len, ptr))) != -1) {
            printf("%s", line);
            val--;
        }
        if(read == -1) {
            printf("\nKoniec pliku!");
            break;
        }
        getc(stdin);
        a = getc(stdin);
    }

    free(line);
    fclose(ptr);
}

int main(void) {
    //Zadanie 5
    Task5("settlement.txt", "bills.txt");

    //Zadanie 6
    Task6("settlement_task6.txt", "bills.txt");

    //Zadanie 7
    Task7("input.txt", "statistics.dat");

    //Zadanie 8
    char* read;
    char* write;

    printf("Podaj plik do odczytania:\n");
    read = get_name();
    printf("Podaj plik do wpisania wyniku:\n");
    write = get_name();
    Task5(read, write);
    free(read);free(write);

    printf("Podaj plik do odczytania:\n");
    read = get_name();
    printf("Podaj plik do wpisania wyniku:\n");
    write = get_name();
    Task6(read, write);
    free(read);free(write);

    printf("Podaj plik do odczytania:\n");
    read = get_name();
    printf("Podaj plik do wpisania wyniku:\n");
    write = get_name();
    Task7(read, write);
    free(read);free(write);

    //Zadanie 9

    int val;
    printf("Podaj nazwe pliku: \n");
    char *file = get_name();
    printf("Podaj liczbe ostatnich linii do wypisania: \n");
    scanf("%d", &val);
    tail(file, val);
    free(file);

    //Zadanie 10

    printf("Podaj nazwe pliku: \n");
    file = get_name();
    more(file);
    free(file);

    return 0;
}