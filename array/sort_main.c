#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int main(void)
{
    /*int a[10] = {9,8,7,6,5,4,3,2,1,0};
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    sort_selection(a, 10);
    printf("Selection sorted\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int b[10] = {9,8,7,6,5,4,3,2,1,0};
    sort_insertion(b, 10);
    printf("Insertion sorted\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
*/
    int a[5] = {10,6,8,15,2};
    max_sort_selection(a, 5);

    int x = 11, y = 10;
    printf("%d\n", x|y);

    return 0;
}
