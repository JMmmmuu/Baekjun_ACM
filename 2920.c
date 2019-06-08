/*************************************************
 ****************** Note Scale *******************
 ******************** Yuseok *********************
 ******************** 190000 *********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[8];
    int res;

    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }

    res = arr[1] - arr[0];
    if (res != 1 && res != -1)
        printf("mixed\n");
    else {
        for (int i = 2; i < 8; i++) {
            if (arr[i] - arr[i-1] != res) {
                res = 0;
                break;
            }
        }
        
        if (res == 1) printf("ascending\n");
        else if (res == -1) printf("descending\n");
        else printf("mixed\n");
    }

    return 0;
}
