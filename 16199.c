#include <stdio.h>
#include <stdlib.h>

int main() {
    int by, bm, bd;
    int ny, nm, nd;
    scanf("%d%d%d", &by, &bm, &bd);
    scanf("%d%d%d", &ny, &nm, &nd);

    int man, nai, yeon;
    man = ny - by;
    if (man > 0) {
        if (bm > nm) man -= 1;
        else if (bm == nm)
            if (bd > nd) man -= 1;
    }
    nai = ny - by + 1;
    yeon = ny - by;

    printf("%d\n%d\n%d\n", man, nai, yeon);


    return 0;
}
