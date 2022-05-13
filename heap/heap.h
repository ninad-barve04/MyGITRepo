#ifndef HEAP_H
#define HEAP_H (1)


#define SIZE (50)

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

