/**
 * @file main.c
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief main function file for max heap implementation
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "heap_sort.h"

int main(int argc, char const *argv[])
{
    Heap heap;
    initHeap(&heap);
    int array[] = {10, 5, 20, 25, 30, 5, 100};
    for (int i = 0; i < 7; i++) {
        insertHeap(&heap, array[i]);
    }
    
    traverseHeap(heap);

    int x;
    for (int j = 0; j < 7; j++) {
        x = deleteHeap(&heap);
        printf("Deleted element is: %d\n", x);
    }

    traverseHeap(heap);

    FILE *to_sort = fopen("to_sort.txt", "r");
    int *heap_sort_array_ascending = NULL;
    int *heap_sort_array_descending= NULL;
    int heap_sort_array_ascending_size = heap_sort(to_sort, ASCENDING, &heap_sort_array_ascending);
    int heap_sort_array_descending_size = heap_sort(to_sort, DESCENDING, &heap_sort_array_descending);
    for (int i = 0; i < heap_sort_array_ascending_size; i++) {
        printf("%d - ", heap_sort_array_ascending[i]);
    }
    printf("END\n");
    for (int i = 0; i < heap_sort_array_descending_size; i++) {
        printf("%d - ", heap_sort_array_descending[i]);
    }
    printf("END\n");
    free(heap_sort_array_ascending);
    free(heap_sort_array_descending);

    return 0;
}

