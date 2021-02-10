#include "core/core.h"

int main(void) {
    FILE *fout = fopen("dump", "w");
    core_generate(4, fout);
    fclose(fout);
}

