#include "util.h"

int checar_letra(char letra) {
    if (letra >= 'a' && letra <= 'z') return 1;
    if (letra >= 'A' && letra <= 'Z') return -1;
    return 0;
}
