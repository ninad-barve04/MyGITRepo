/**
 * @file heap_sort.h
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Heap sort header file
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef HEAP_SORT_H
#define HEAP_SORT_H (1)

#define ASCENDING (25)
#define DESCENDING (50)

#include <stdio.h>
#include "heap.h"

int heap_sort(FILE *unsorted_fp, int order, int **output);

#endif // HEAP_SORT_H