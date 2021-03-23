//Artur Czarnik, zestaw 2
#include <bitset>
#include <iostream>

typedef unsigned short int usi;

using namespace std;

bitset<16> print(usi set) {
    return std::bitset<16> (set);
}

usi complement(usi set) {
    return ~set;
}

usi intersection(usi set1, usi set2) {
    return (set1 & set2);
}

usi sum(usi set1, usi set2) {
    return (set1 | set2);
}

usi substract(usi set1, usi set2) {
    return (set1 & ~set2);
}

usi symmetric(usi set1, usi set2) {
    return (set1 ^ set2);
}

bool exists(usi set, int n) {
    usi set2 = 32768; // 1000 0000 0000 0000
    set <<= (n - 1);
    return (set2 & set) == set2;
}

int power(usi set) {
    usi set2 = 32768; // 1000 0000 0000 0000
    int a = 0; //moc zbioru
    int i = 0; //iteracja

    while(i != 16) {
        i++;
        if ((set & set2) == set2) //jesli iloczyn zbioru set i set2 jest rowny set2, to znaczy ze wystepuje 1
            a++; //zwiekszamy moc o 1
        set <<= 1; //przesuwamy bity w lewo
    }

    return a;
}

usi set_1(usi set, int n) {
    return (1 << (16 - n) | set);
}

usi set_0(usi set, int n) {
    return (set & ~(1 << (16 - n)));
}

int main() {
    usi setA;
    usi setB;

    cout << "Podaj zbior A:";
    std::cin >> setA;
    cout << "Podaj zbior B:";
    std::cin >> setB;

    cout << "Zbior A: " << print(setA) << " (" << setA << ")" << endl;
    cout << "Zbior B: " << print(setB) << " (" << setB << ")" << endl;

    cout << "Dopelnienie zbioru A: " << print(complement(setA)) << endl;
    cout << "Dopelnienie zbioru B: " << print(complement(setB)) << endl;

    cout << "Przeciecie zbiorow A i B: " << print(intersection(setA, setB)) << endl;

    cout << "Suma zbiorow A i B: " << print(sum(setA, setB)) << endl;

    cout << "Roznica zbiorow A i B: " << print(substract(setA, setB)) << endl;

    cout << "Roznica symetryczna zbiorow A i B: " << print(symmetric(setA, setB)) << endl;

    int n;

    cout << "Podaj, ktory n-ty element sprawdzic:";
    cin >> n;
    cout << "Czy " << n << "-ty wyraz istnieje w zbiorze A? " << std::boolalpha << exists(setA, n) << endl;
    cout << "Czy " << n << "-ty wyraz istnieje w zbiorze B? " << std::boolalpha << exists(setB, n) << endl;

    cout << "Podaj, ktory n-ty element dodac:";
    cin >> n;
    setA = set_1(setA, n);
    setB = set_1(setB, n);
    cout << "Zbior A: " << print(setA) << " (" << setA << ")" << endl;
    cout << "Zbior B: " << print(setB) << " (" << setB << ")" << endl;

    cout << "Podaj, ktory n-ty element usunac:";
    cin >> n;
    setA = set_0(setA, n);
    setB = set_0(setB, n);
    cout << "Zbior A: " << print(setA) << " (" << setA << ")" << endl;
    cout << "Zbior B: " << print(setB) << " (" << setB << ")" << endl;

    cout << "Moc zbioru A: " << power(setA) << endl;
    cout << "Moc zbioru B: " << power(setB) << endl;

    return 0;
}
