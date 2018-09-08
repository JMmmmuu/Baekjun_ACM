#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int month, date;
    srand(time(NULL));
    
    month = rand() % 9 + 1;
    switch(month) {
        case 2:
            date = rand() % 28 + 1; break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            date = rand() % 31 + 1; break;
        case 9:
            date = rand() % 8 + 1; break;
        default:
            date = rand() % 30 + 1; break;
    }

    printf("2018%02d%02d", month, date);

    return 0;
}
