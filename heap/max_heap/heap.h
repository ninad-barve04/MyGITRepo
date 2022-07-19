/**
 * @file heap.h
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Max heap header file
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HEAP_H
#define HEAP_H (1)

/**
 * @brief Default heap array initialization size
 * 
 */
#define SIZE (50)

/**
 * @brief Heap struct
 * @brief Contains size, integer array and index of next insertion point
 * 
 */
typedef struct Heap {
    int size;
    int *array;
    int next;   // This is not the index of the last element, but the index of 
                // the next location where a newnode will be added
} Heap;

void initHeap(Heap *heap);
void insertHeap(Heap *heap, int data);
void heapify(Heap *heap, int index);
void traverseHeap(Heap heap);
int deleteHeap(Heap *heap);
void heapifyDelete(Heap *heap, int largest);


#endif // HEAP_H

