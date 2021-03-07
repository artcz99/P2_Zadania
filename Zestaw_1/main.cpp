//Artur Czarnik, Zestaw 1

#include <iostream>
#include <cstdlib>

void print_arr(int *arr, int size) { //prints each value from dynamic array
    for (int i = 0; i < size; i++)
        std::cout << *(arr + i) << ' ';
    std::cout << std::endl;
}

int *random_arr(int size) { //generates an array with random values
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        *(arr + i) = rand() % 11;
    return arr;
}

int max_val(int *arr, int size) { //returns maximal value from given array
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max)
            max = *(arr + i);
    }
    return max;
}

int *reverse_array(int *arr, int size) { //reverses given array
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }

    return arr;
}

int *shift_left(int *arr, int size, int shift) {
    shift %= size;
    int temp;
    for (int i = 0; i < shift; i++) {
        temp = *(arr);
        for (int j = 1; j < size; j++) {
            *(arr + j - 1) = *(arr + j);
        }
        *(arr + size - 1) = temp;
    }
    return arr;
}

int *bubble_sort(int *arr, int size) { //sorts given array using the bubble sort algorithm
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    return arr;

}

int *merge_arrays(int *arr1, int size1, int *arr2, int size2) { //merges two sorted arrays into a sorted array
    int *return_arr = new int[size1 + size2];
    int i = 0, j = 0;
    while (i < size1 or j < size2) {
        if (*(arr1 + i) < *(arr2 + j)) {
            if (i >= size1) {
                *(return_arr + i + j) = *(arr2 + j);
                j++;
            } else {
                *(return_arr + i + j) = *(arr1 + i);
                i++;
            }
        } else {
            if (j >= size2) {
                *(return_arr + i + j) = *(arr1 + i);
                i++;
            } else {
                *(return_arr + i + j) = *(arr2 + j);
                j++;
            }
        }
    }
    return return_arr;
}

int *multiply(int *arr1, int size1, int *arr2, int size2) { //multiplies polynomials and returns the result as an array
    int *return_arr = new int[size1 + size2 - 1];
    for (int i = 0; i < size1 + size2 - 1; i++) {
        *(return_arr + i) = 0;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++)
            *(return_arr + i + j) += *(arr1 + i) * (*(arr2 + j));
    }

    return return_arr;
}


int main() {
    std::cout << "Zadanie 0" << std::endl;
    int size;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;
    int *arr = random_arr(size);
    std::cout << "Losowa tablica: ";
    print_arr(arr, size);
    std::cout << std::endl;

    std::cout << "Zadanie 1" << std::endl;
    std::cout << "Maksymalna wartosc to: " << max_val(arr, size) << std::endl;
    std::cout << std::endl;

    std::cout << "Zadanie 2" << std::endl;
    arr = reverse_array(arr, size);
    std::cout << "Odwrocona kolejnosc: " << max_val(arr, size) << std::endl;
    print_arr(arr, size);
    std::cout << std::endl;

    std::cout << "Zadanie 3" << std::endl;
    int shift;
    std::cout << "O ile pol w lewo przesunac elementy w tablicy: ";
    std::cin >> shift;
    arr = shift_left(arr, size, shift);
    print_arr(arr, size);
    delete[] arr;
    std::cout << std::endl;

    std::cout << "Zadanie 4" << std::endl;
    int size_n4, size_m4;
    std::cout << "Podaj rozmiar tablicy n: ";
    std::cin >> size_n4;
    std::cout << "Podaj rozmiar tablicy m: ";
    std::cin >> size_m4;
    int *arr_n4 = random_arr(size_n4);
    int *arr_m4 = random_arr(size_m4);
    std::cout << "Tablica n (przed sortowaniem): ";
    print_arr(arr_n4, size_n4);
    std::cout << "Tablica m (przed sortowaniem): ";
    print_arr(arr_m4, size_m4);
    arr_n4 = bubble_sort(arr_n4, size_n4);
    arr_m4 = bubble_sort(arr_m4, size_m4);
    std::cout << "Tablica n (po sortowaniu): ";
    print_arr(arr_n4, size_n4);
    std::cout << "Tablica m (po sortowaniu): ";
    print_arr(arr_m4, size_m4);
    int merged_arr_size = size_n4 + size_m4;
    int *merged_arr = merge_arrays(arr_n4, size_n4, arr_m4, size_m4);
    std::cout << "Tablica powstala w wyniku scalenia tablic n i m: ";
    print_arr(merged_arr, merged_arr_size);
    delete[] arr_n4;
    delete[] arr_m4;
    std::cout << std::endl;

    std::cout << "Zadanie 5" << std::endl;
    int size_n5, size_m5;
    std::cout << "Podaj rozmiar tablicy n: ";
    std::cin >> size_n5;
    std::cout << "Podaj rozmiar tablicy m: ";
    std::cin >> size_m5;
    int *arr_n5 = random_arr(size_n5);
    int *arr_m5 = random_arr(size_m5);
    std::cout << "Tablica n: ";
    print_arr(arr_n5, size_n5);
    std::cout << "Tablica m: ";
    print_arr(arr_m5, size_m5);
    std::cout << "Wynik mnozenia wielomianow: ";

    print_arr(multiply(arr_n5, size_n5, arr_m5, size_m5), size_n5 + size_m5 - 1);
    delete[] arr_n5;
    delete[] arr_m5;
    std::cout << std::endl;

    std::cout << "Zadanie 6" << std::endl;


}
