#include <iostream>
#include "Prison.h"

int main() {
    Prison* prison = Prison::getInstance();

    for (int i = 0; i < prisoner_count; i++) {
        for (int j = 0; j < prisoner_count; j++) {
            printf("use prisoner %d fetch box %d, get ticket %d, ", i+1, j+1, prison->prisoner_fetch(i, j));
            printf("has solved: %s\n", prison->get_state(i) ? "true" : "false");
        }
        putchar('\n');
    }
    

    return 0;
}