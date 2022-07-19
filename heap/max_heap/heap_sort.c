/**
 * @file heap_sort.c
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Heap sort function
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

/**
 * @brief Heap sort function
 * 
 * @param unsorted_fp (File pointer to original unsorted integer file)
 * @param order (Acending sort or descending sort)
 * @param output (Output array)
 * @return int count
 */
int heap_sort(FILE *unsorted_fp, int order, int **output) {

    Heap heap;
    initHeap(&heap);
    
    int num;

    int count = 0;
    while(!feof(unsorted_fp)) {
        fscanf(unsorted_fp, "%d", &num);
        count++;
    }
    rewind(unsorted_fp);

    int *op_array = (int *)malloc(sizeof(int) * count);

    num = -1;
    while (!feof(unsorted_fp)) {
        fscanf(unsorted_fp, "%d", &num);
        insertHeap(&heap, num);
    }
    rewind(unsorted_fp);
    
    num = 0;

    // order = 1 is ascending. So deleted from MAX HEAP are inserted in rear of 
    // array
    if (order == ASCENDING) {
        for (int i = 0; i < count; i++) {
            op_array[count - 1 - i] = deleteHeap(&heap);
        }
    } else if (order == DESCENDING) {
        for (int i = 0; i < count; i++) {
            op_array[i] = deleteHeap(&heap);
        }
    }
    *output = op_array;
    return count;
}