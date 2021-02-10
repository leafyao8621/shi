#include <stdio.h>
#include "../util/mt19937.h"

void core_generate(int n, FILE *fout) {
    char *base = "诗是食湿屎";
    char buf[16];
    struct MT19937 gen[5];
    struct MT19937 *gen_iter = gen;
    buf[15] = 0;
    for (char i = 0, *ii = base; i < 5; ++i, ii += 3, ++gen_iter) {
        mt19937_initialize(gen_iter, ((*ii & 0xf) << 12) |
                                     ((ii[1] & 0x3f) << 6) |
                                     (ii[2] & 0x3f));
    }
    fprintf(fout, "%s\n", base);
    for (int i = 0; i < n; ++i) {
        gen_iter = gen;
        for (char j = 0, *jj = buf; j < 5; ++j, jj += 3, ++gen_iter) {
            unsigned temp = (mt19937_gen(gen_iter) % 20989) + 0x4E00;
            *jj = 0xE0 | ((temp >> 12) & 0xf);
            jj[1] = 0x80 | ((temp >> 6) & 0x3f);
            jj[2] = 0x80 | (temp & 0x3f);
        }
        fprintf(fout, "%s\n", buf);
    }
}
