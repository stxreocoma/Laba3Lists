#include "doubly_linked_list.h"
#include <iostream>

class laba {
public:
    TwoList<char> String;
    void rmDots();
    void rmDot();
    //private:
    void removeDot(int, int);
};

void laba::rmDots() {
    bool letter_flg = false, dot_flg = false;
    int dot_index = -1, dot_count = 0, dif = 0, length_dif = 0;
    for (int i = 0; i < String.size(); i++) {
        if (isalpha(String[i - dif]->data)) {
            letter_flg = true;
        }
        if (String[i - dif]->data == '.' && letter_flg && !dot_flg) {
            dot_index = i - dif;
            dot_count++;
            dot_flg = true;
        }
        else if (String[i - dif]->data == '.' && dot_index != -1) {
            dot_count++;
        }
        else if (dot_index != -1 && dot_count % 2 != 0 && dot_count > 1 && letter_flg) {
            //dot(String, String.size() - length_dif, dot_index, dot_count);
            length_dif += dot_count - 1;
            dif += dot_count - 1;
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(String[i - dif]->data)) {
                letter_flg = false;
            }
        }
        else if (dot_index != -1 && dot_count % 2 == 0 && String[i - dif]->data != '.') {
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(String[i - dif]->data)) {
                letter_flg = false;
            }
        }
    }
    if (dot_index != -1 && dot_count % 2 != 0) {
        for (int index = dot_index + 1; index < String.size() - length_dif; index++) {
            String[index]->data = ' ';
        }
    }
}

void laba::rmDot() {
    bool letter_flg = false, dot_flg = false;
    int dot_index = -1, dot_count = 0;
    for (int i = 0; i < String.size(); i++) {
        if (isalpha(String[i]->data)) {
            letter_flg = true;
        }
        if (String[i]->data == '.' && letter_flg && !dot_flg) {
            dot_index = i;
            dot_count++;
            dot_flg = true;
        }
        else if (String[i]->data == '.' && dot_index != -1) {
            dot_count++;
        }
        else if (dot_index != -1 && dot_count % 2 != 0 && dot_count > 1 && letter_flg) {
            removeDot(dot_index, dot_count);
            return rmDot();
        }
        else if (dot_index != -1 && dot_count % 2 == 0 && String[i]->data != '.') {
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(String[i]->data)) {
                letter_flg = false;
            }
        }
    }
    if (dot_index != -1 && dot_count % 2 != 0) {
        for (int index = dot_index + 1; index < String.size(); index++) {
            String.rmDot(index);
        }
    }
}

void laba::removeDot(const int dot_index, const int dot_count) {
    for (int i = dot_index; i < dot_index + dot_count; i++) {
        String.rmDot(i);
    }
}

int main() {
    laba Laba;
    for (int i = 0; i < 6; i++) {
        Laba.String.push_back(getchar());
    }
    Laba.removeDot(1, 3);
    Laba.String.print();
}