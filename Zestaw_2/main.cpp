//Artur Czarnik, zestaw 2

#include <iostream>
#include <string>

struct node {
    std::string val;
    node *next_node;

    node();
};

node::node() {
    next_node = 0;
}

struct list {
    node *first_node;

    list();

    void print();

    void add(std::string);

    bool contain(std::string);

    void remove(std::string);

    void removeAll(std::string);

    int length();

    bool isEmpty();

    void clear();

    int indexOf(std::string);

    void removeRep();

    void addAtIndex(std::string, int);

    bool hasAppeared(std::string[], int, std::string);

    std::string *toArray();

    void reverse();
};

list::list() {
    first_node = 0;
}

void list::print() {
    node *temp = first_node;
    while (temp) {
        std::cout << temp->val << "->";
        temp = temp->next_node;
    }
    std::cout << "nullptr";
    std::cout << std::endl;
}

void list::add(std::string new_value) {
    node *new_node = new node;

    new_node->val = new_value;
    if (first_node == 0) {
        first_node = new_node;
    } else {
        node *temp = first_node;
        while (temp->next_node) {
            temp = temp->next_node;
        }
        temp->next_node = new_node;
    }
}

bool list::contain(std::string search) {
    node *temp = first_node;
    while (temp) {
        if (temp->val == search) {
            return true;
        }
        temp = temp->next_node;
    }
    return false;
}

void list::remove(std::string search_value) {
    if (first_node->val == search_value) {
        node *temp = first_node->next_node;
        delete first_node;
        first_node = temp;
        return;
    }
    node *temp = first_node;
    while (temp->next_node->val != search_value) {
        temp = temp->next_node;
        if (temp->next_node == 0) return;
    }
    if (temp->next_node->next_node == 0) {
        delete temp->next_node;
        temp->next_node = 0;
        return;
    }
    node *temp2 = temp->next_node->next_node;
    delete temp->next_node;
    temp->next_node = temp2;
}

int list::length() {
    node *temp = first_node;
    int i = 0;
    while (temp) {
        i++;
        temp = temp->next_node;
    }
    return i;
}

bool list::isEmpty() {
    return first_node == 0;
}

void list::clear() {
    node *temp = first_node;
    node *temp2;
    while (temp) {
        temp2 = temp->next_node;
        delete temp;
        temp = temp2;
    }
    first_node = 0;
}

int list::indexOf(std::string search_value) {
    int index = -1;
    bool exists = false; // zakładam, że szukany element nie istnieje
    node *temp = first_node;
    while (temp) {
        index++;
        if (temp->val == search_value) {
            exists = true;
            break;
        }
        temp = temp->next_node;
    }
    if (!exists) return -1;
    return index;
}

void list::addAtIndex(std::string new_value, int index) {
    if (index < 0) return;
    if (index >= length()) {
        node *temp = first_node;
        while (temp->next_node) {
            temp = temp->next_node;
        }
        node *new_node = new node;
        new_node->val = new_value;
        temp->next_node = new_node;
        return;
    }
    if (index == 0) {
        node *temp = first_node;
        node *new_node = new node;
        new_node->val = new_value;
        first_node = new_node;
        first_node->next_node = temp;
        return;
    }
    node *temp = first_node;
    int i = 0;
    while (i + 1 != index) {
        i++;
        temp = temp->next_node;
    }
    node *temp2 = temp->next_node;
    node *new_node = new node;
    new_node->val = new_value;
    temp->next_node = new_node;
    new_node->next_node = temp2;
}

void list::removeAll(std::string search_value) {
    if (!contain(search_value)) return;
    int fixed_length = length();
    for (int i = 0; i < fixed_length; i++) {
        remove(search_value);
    }
}

void list::removeRep() {
    int array_size = length();
    std::string array[array_size];
    for (int i = 0; i < array_size; i++) {
        array[i] = "";
    }
    int i = 0;
    node *temp = first_node;
    while (temp) {
        if (hasAppeared(array, array_size, temp->val)) {
            remove(temp->val);
            temp = temp->next_node;
        } else {
            array[i] = temp->val;
            i++;
            temp = temp->next_node;
        }
    }
}

bool list::hasAppeared(std::string array[], int length, std::string value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) return true;
    }
    return false;
}

std::string *list::toArray() {
    int arr_size = length();
    std::string *arr = new std::string[arr_size];
    node *temp = first_node;
    int i = 0;
    while (temp) {
        *(arr + i) = temp->val;
        temp = temp->next_node;
        i++;
    }
    return arr;
}

void list::reverse() {
    std::string *arr = toArray();
    int arr_size = length();
    clear();
    for(int i = arr_size; i > 0; i--) {
        add(*(arr + i - 1));
    }
}

void print_arr(std::string *arr, int size) { //prints each value from dynamic array
    for (int i = 0; i < size; i++)
        std::cout << *(arr + i) << ' ';
    std::cout << std::endl;
}

int main() {
    list *data = new list;
    std::cout << "add (dodaj na koniec listy element e)" << std::endl;
    data->add("Patrycja");
    data->add("Gabriel");
    data->add("Lukasz");
    data->add("Pawel");
    data->add("Patrycja");
    data->add("Paulina");
    data->add("Pawel");
    data->print();
    std::cout << std::endl;
    std::cout << "contain (sprawdz czy lista zawiera element o nazwie n)" << std::endl;
    std::cout << data->contain("Dorota") << std::endl;
    std::cout << data->contain("Pawel") << std::endl;
    std::cout << std::endl;
    std::cout << "remove (usun pierwsze wystapienie elementu o nazwie n)" << std::endl;
    data->remove("Pawel");
    data->print();
    std::cout << std::endl;
    std::cout << "removeAll (usun wszystkie wystapienia elementu o nazwie n)" << std::endl;
    data->removeAll("Patrycja");
    data->print();
    std::cout << std::endl;
    std::cout << "length (zwroc dlugosc listy)" << std::endl;
    std::cout << data->length() << std::endl;
    std::cout << std::endl;
    std::cout << "isEmpty (sprawdz czy lista jest pusta)" << std::endl;
    std::cout << data->isEmpty() << std::endl;
    std::cout << std::endl;
    std::cout << "indexOf (zwroc indeks elementu o nazwie n)" << std::endl;
    std::cout << data->indexOf("Lukasz") << std::endl;
    std::cout << data->indexOf("Andrzej") << std::endl;
    std::cout << std::endl;
    std::cout << "add (dodaj element e na pozycje o indeksie i)" << std::endl;
    data->addAtIndex("Pawel", 4);
    data->print();
    std::cout << std::endl;
    std::cout << "removeRep (usun wszystkie powtorzenia)" << std::endl;
    data->removeRep();
    data->print();
    std::cout << std::endl;
    std::cout << "reverse (odwroc liste)" << std::endl;
    data->reverse();
    data->print();
    std::cout << std::endl;
    std::cout << "toArray (zwroc tablice zawierajaca wszystkie elementy)" << std::endl;
    print_arr(data->toArray(), data->length());
    std::cout << std::endl;
    std::cout << "clear (usun wszystkie elementy z listy)" << std::endl;
    data->clear();
    std::cout << data->isEmpty() << std::endl;
    delete data;
}