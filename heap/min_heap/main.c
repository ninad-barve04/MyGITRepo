/**
 * @file main.c
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief main function file for min heap implementation
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#include "heap.h"

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

    return 0;
}

