/**
 * @file heap.c
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Min heap finctions
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


/**
 * @brief Initialize the heap with a predefined size (50 elements)
 * 
 * @param heap (Heap *) pointer reference to the heap
 */
void initHeap(Heap *heap){
    heap->size = SIZE;
    heap->array = (int *)malloc(sizeof(int) * (heap->size));
    heap->next = 0;
}


/**
 * @brief Insert a new element to the heap
 * 
 * @param heap (Heap *) pointer reference to the heap
 * @param data (int) new element to be inserted
 */
void insertHeap(Heap *heap, int data) {
    printf("Inserting data %d\n", data);
    if (heap->next >= heap->size) {
        heap->array = realloc(heap->array, 2*(heap->size)*sizeof(int));
        heap->array[heap->next] = data;
        heap->next++;
    } else {
        heap->array[heap->next] = data;
        heap->next++;
    }
    heapify(heap, (heap->next)-1);
    printf("Inserted data %d\n\n", data);
    return;
}


/**
 * @brief Heapify for MIN Heap after insertion. Bottom up heapification
 * 
 * @param heap  (Heap *) pointer reference to the heap
 * @param index (int) index of new added element to heap
 */
void heapify(Heap *heap, int index) {
    
    if (heap->array[index] < heap->array[(index-1)/2]) {
        int temp = 0;
        temp = heap->array[(index-1)/2];
        heap->array[(index-1)/2] = heap->array[index];
        heap->array[index] = temp;
        heapify(heap, (index-1)/2);
    } else {
        return;
    }
}


/**
 * @brief Level order traversal for the heap
 * 
 * @param heap (Heap) direct reference to the heap
 */
void traverseHeap(Heap heap) {
    int index = 0;
    while (index < heap.size) {
        printf("%d - ", heap.array[index]);
        index++;
    }
    printf("END\n");
}


/**
 * @brief Delete the topmost element from the heap
 * 
 * @param heap 
 * @return int 
 */
int deleteHeap(Heap *heap) {
    int root = heap->array[0];
    printf("root == %d\n", root);
    --(heap->next);
    int temp = 0;
    temp = heap->array[0];
    heap->array[0] = heap->array[heap->next];
    heap->array[heap->next] = temp;

    
    heapifyDelete(heap, 0);

    return root;
}


/**
 * @brief Heapify for MIN heap after deletion. Top down heapification
 * 
 * @param heap 
 * @param root 
 */
void heapifyDelete(Heap *heap, int root) {
    int smallest = root;
    int left  = 2 * smallest + 1;
    int right = 2 * smallest + 2;

    // If left child smaller than root
    if (left < heap->next && heap->array[root] > heap->array[left]) {
        smallest = left;
    }
    
    // If right child greater than root
    if (right < heap->next && heap->array[smallest] > heap->array[right]) {
        smallest = right;
    }

    // 
    if (smallest != root) {
        int temp = 0;
        temp = heap->array[smallest];
        heap->array[smallest] = heap->array[root];
        heap->array[root] = temp;

        heapifyDelete(heap, smallest);
    }

}