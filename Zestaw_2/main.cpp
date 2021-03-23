//Artur Czarnik
#include <iostream>

using namespace std;
//cord - sznur, bead - koralik

struct bead {
    int kr;

    bead *next_bead;

    struct wbe {
        bead *ptr;
        wbe *next_wbe;

        wbe();
    };

    wbe *first_wbe;

    struct bor {
        bead *ptr;
        bor *next_bor;

        bor();
    };

    bor *first_bor;

    bead();
};

bead::bor::bor() {
    next_bor = NULL;
}

bead::wbe::wbe() {
    next_wbe = NULL;
}

bead::bead() {
    next_bead = NULL;
}

struct cord {
    char sn_1;
    char sn_2;
    char sn_3;

    bead *first_bead;

    cord *next_cord;

    void add_bead(int kr);

    void delete_bead(int kr);

    bead *get_bead_pointer(int kr);

    cord();
};

cord::cord() {
    first_bead = NULL;
    next_cord = NULL;
}

void cord::add_bead(int kr) {
    bead *new_bead = new bead;
    new_bead->kr = kr;

    if (first_bead == NULL) {
        first_bead = new_bead;
    } else {
        if (first_bead->kr > new_bead->kr) {
            bead *temp = first_bead;
            first_bead = new_bead;
            first_bead->next_bead = temp;
        } else {
            if (first_bead->kr == new_bead->kr) {
                delete new_bead;
                return;
            }
            if (first_bead->next_bead == NULL) {
                if (first_bead->kr == new_bead->kr) {
                    delete new_bead;
                    return;
                }
                first_bead->next_bead = new_bead;
            } else {
                bead *temp = first_bead;
                while (temp->next_bead) {
                    if (temp->next_bead->kr > new_bead->kr) {
                        bead *temp2 = temp->next_bead;
                        temp->next_bead = new_bead;
                        new_bead->next_bead = temp2;
                        return;
                    }
                    if (temp->next_bead->kr == new_bead->kr) {
                        delete new_bead;
                        return;
                    }
                    temp = temp->next_bead;
                }
                temp->next_bead = new_bead;
            }
        }
    }
}

void cord::delete_bead(int kr) {
    if (first_bead->kr == kr) {
        bead *temp = first_bead->next_bead;
        delete first_bead;
        first_bead = temp;
        return;
    }
    bead *temp = first_bead;
    while (temp->next_bead->kr != kr) {
        temp = temp->next_bead;
        if (temp->next_bead == NULL) return;
    }
    if (temp->next_bead->next_bead == NULL) {
        delete temp->next_bead;
        temp->next_bead = NULL;
        return;
    }
    bead *temp2 = temp->next_bead->next_bead;
    delete temp->next_bead;
    temp->next_bead = temp2;
}

bead *cord::get_bead_pointer(int kr) {
    bead *temp = first_bead;
    while (temp) {
        if (kr == temp->kr) return temp;
        temp = temp->next_bead;
    }
    return NULL;
}


struct list {
    cord *first_cord;

    list();

    void print();

    void S(char sn_1, char sn_2, char sn_3);

    void B(int kr, char sn_1, char sn_2, char sn_3);

    void L(int kr1, char sn1_1, char sn1_2, char sn1_3, int kr2, char sn2_1, char sn2_2, char sn2_3);

    void D(int kr, char sn_1, char sn_2, char sn_3);

    void R(char sn_1, char sn_2, char sn_3);

    cord *get_cord_pointer(char sn_1, char sn_2, char sn_3);

    int compare_cord_id(cord *s1_x, cord *s2_x);

    void delete_all_beads(cord *temp_cord);

    void link(bead* bead_1, bead* bead_2);
};

list::list() {
    first_cord = NULL;
}

void list::print() {
    cord *temp = first_cord;
    while (temp) {
        std::cout << temp->sn_1 << temp->sn_2 << temp->sn_3 << endl;
        bead *temp_bead = temp->first_bead;
        while (temp_bead) {
            std::cout << temp_bead->kr << std::endl;
            temp_bead = temp_bead->next_bead;
        }
        temp = temp->next_cord;
    }
}

void list::S(char sn_1, char sn_2, char sn_3) {
    cord *new_cord = new cord;
    new_cord->sn_1 = sn_1;
    new_cord->sn_2 = sn_2;
    new_cord->sn_3 = sn_3;

    if (first_cord == NULL) {
        first_cord = new_cord;
    } else {
        if (compare_cord_id(first_cord, new_cord) == -1) {
            delete new_cord;
            return;
        }
        if (compare_cord_id(first_cord, new_cord) == 1) {
            cord *temp = first_cord;
            first_cord = new_cord;
            first_cord->next_cord = temp;
        } else {
            if (first_cord->next_cord == NULL) {
                if (compare_cord_id(first_cord, new_cord) == -1) {
                    delete new_cord;
                    return;
                }
                first_cord->next_cord = new_cord;
            } else {
                cord *temp = first_cord;
                while (temp->next_cord) {
                    if (compare_cord_id(temp->next_cord, new_cord) == 1) {
                        cord *temp2 = temp->next_cord;
                        temp->next_cord = new_cord;
                        new_cord->next_cord = temp2;
                        return;
                    }
                    if (compare_cord_id(temp, new_cord) == -1) {
                        delete new_cord;
                        return;
                    }
                    temp = temp->next_cord;
                }
                temp->next_cord = new_cord;
            }
        }
    }
}

int list::compare_cord_id(cord *s1, cord *s2) {//1 s1_x higher, 0 s2_x higher, -1 equal
    if (s1->sn_1 > s2->sn_1) return 1;
    else if (s1->sn_1 < s2->sn_1) return 0;
    else {
        if (s1->sn_2 > s2->sn_2) return 1;
        else if (s1->sn_2 < s2->sn_2) return 0;
        else {
            if (s1->sn_3 > s2->sn_3) return 1;
            else if (s1->sn_3 < s2->sn_3) return 0;
            else return -1;
        }
    }
}

void list::B(int kr, char sn_1, char sn_2, char sn_3) {
    if (first_cord == NULL) return;
    if (kr > 999 or kr < 100) return;
    cord *temp = get_cord_pointer(sn_1, sn_2, sn_3);
    if (temp == NULL) return;

    temp->add_bead(kr);
}

void list::delete_all_beads(cord *temp_cord) {
    bead *tempbead1 = temp_cord->first_bead;
    bead *tempbead2;
    while (tempbead1) {
        tempbead2 = tempbead1->next_bead;
        delete tempbead1;
        tempbead1 = tempbead2;
    }
}

void list::R(char sn_1, char sn_2, char sn_3) {
    if (first_cord->sn_1 == sn_1 && first_cord->sn_3 == sn_3 && first_cord->sn_3 == sn_3) {
        cord *temp = first_cord->next_cord;
        delete_all_beads(first_cord);
        delete first_cord;
        first_cord = temp;
        return;
    }
    cord *temp = first_cord;
    while (!(temp->next_cord->sn_1 == sn_1 && temp->next_cord->sn_3 == sn_3 && temp->next_cord->sn_3 == sn_3)) {
        temp = temp->next_cord;
        if (temp->next_cord == NULL) return;
    }
    if (temp->next_cord->next_cord == NULL) {
        delete_all_beads(temp->next_cord);
        delete temp->next_cord;
        temp->next_cord = NULL;
        return;
    }
    cord *temp2 = temp->next_cord->next_cord;
    delete temp->next_cord;
    temp->next_cord = temp2;
}

void list::D(int kr, char sn_1, char sn_2, char sn_3) {
    if (kr > 999 or kr < 100) return;
    cord *temp_cord = get_cord_pointer(sn_1, sn_2, sn_3);
    if (temp_cord == NULL || temp_cord->first_bead == NULL) return;
    temp_cord->delete_bead(kr);
}

cord *list::get_cord_pointer(char sn_1, char sn_2, char sn_3) {
    cord *temp = first_cord;
    while (temp) {
        if (temp->sn_1 == sn_1 and temp->sn_2 == sn_2 and temp->sn_3 == sn_3) return temp;
        temp = temp->next_cord;
    }
    return NULL;
}

void list::L(int kr1, char sn1_1, char sn1_2, char sn1_3, int kr2, char sn2_1, char sn2_2, char sn2_3) {
    if (first_cord == NULL) return;
    if (kr1 > 999 or kr1 < 100) return;
    if (kr2 > 999 or kr2 < 100) return;
    cord *temp_cord1 = get_cord_pointer(sn1_1, sn1_2, sn1_3);
    if(temp_cord1 == NULL) return;
    bead *temp_bead1 = temp_cord1->get_bead_pointer(kr1);
    if(temp_bead1 == NULL) return;
    cord *temp_cord2 = get_cord_pointer(sn2_1, sn2_2, sn2_3);
    if(temp_cord2 == NULL) return;
    bead *temp_bead2 = temp_cord2->get_bead_pointer(kr2);
    if(temp_bead2 == NULL) return;

    link(temp_bead1, temp_bead2);
}

void list::link(bead *bead_1, bead *bead_2) {
    if(bead_1->)
}

bool is_char(char sn_1, char sn_2, char sn_3) {
    if ((int) sn_1 < 65 || (int) sn_1 > 90) return false;
    if ((int) sn_2 < 65 || (int) sn_2 > 90) return false;
    if ((int) sn_3 < 65 || (int) sn_3 > 90) return false;
    return true;
}

int main() {
    list *cords = new list;
    char a;
    do {
        cin >> a;
        if (a == 'S') { //dodanie do konstrukcji pustego sznura o id sn
            char sn_1, sn_2, sn_3;
            cin >> sn_1 >> sn_2 >> sn_3;
            if (is_char(sn_1, sn_2, sn_3))
                cords->S(sn_1, sn_2, sn_3);
        }
        if (a == 'B') { //dodanie do sznura o id sn koralika o id kr
            int kr;
            cin >> kr;
            char sn_1, sn_2, sn_3;
            cin >> sn_1 >> sn_2 >> sn_3;
            if (is_char(sn_1, sn_2, sn_3))
                cords->B(kr, sn_1, sn_2, sn_3);
        }
        if (a == 'L') {
            /* dodanie wiazania idacego od kolarika o id sK, ze sznura o id sS do
              koralika o id dK ze sznura od id dS */
            int sK;
            cin >> sK;
            char sS_1, sS_2, sS_3;
            cin >> sS_1 >> sS_2 >> sS_3;
            int dK;
            cin >> dK;
            char dS_1, dS_2, dS_3;
            cin >> dS_1 >> dS_2 >> dS_3;
            if (is_char(sS_1, sS_2, sS_3) && is_char(dS_1, dS_2, dS_3)) {
                cords->L(sK, sS_1, sS_2, sS_3, dK, dS_1, dS_2, dS_3);
            }
        }
        if (a == 'U') {
            /* usuniecie wiazania idacego od kolarika o id sK, ze sznura o id sS do
              koralika o id dK ze sznura od id dS */
            int sK;
            cin >> sK;
            char sS_1, sS_2, sS_3;
            cin >> sS_1 >> sS_2 >> sS_3;
            int dK;
            cin >> dK;
            char dS_1, dS_2, dS_3;
            cin >> dS_1 >> dS_2 >> dS_3;
        }
        if (a == 'D') {
            int k;
            cin >> k;
            char s_1, s_2, s_3;
            cin >> s_1 >> s_2 >> s_3;
            if (is_char(s_1, s_2, s_3))
                cords->D(k, s_1, s_2, s_3);
        }
        if (a == 'M') {
            /* przeniesienie koralika o id k ze sznura o id sS na sznur dS razem
             * z wiazaniami */
            int k;
            cin >> k;
            char sS_1, sS_2, sS_3;
            cin >> sS_1 >> sS_2 >> sS_3;
            char dS_1, dS_2, dS_3;
            cin >> dS_1 >> dS_2 >> dS_3;
        }
        if (a == 'R') {
            char s_1, s_2, s_3;
            cin >> s_1 >> s_2 >> s_3;
            if (is_char(s_1, s_2, s_3))
                cords->R(s_1, s_2, s_3);
        }
        if (a == 'P') {
            cords->print();
        }
    } while (a != 'F');

    cord *temp = cords->first_cord;
    cord *temp2;
    while (temp) {
        temp2 = temp->next_cord;
        bead *tempbead1 = temp->first_bead;
        bead *tempbead2;
        while (tempbead1) {
            tempbead2 = tempbead1->next_bead;
            delete tempbead1;
            tempbead1 = tempbead2;
        }
        delete temp;
        temp = temp2;
    }
    delete cords;
    return 0;
}