#include <stdio.h>

#include "heap.h"

int main(int argc, char const *argv[])
{
    Heap heap;
    initHeap(&heap);

    insertHeap(&heap, 10);
    insertHeap(&heap, 5);
    insertHeap(&heap, 20);
    insertHeap(&heap, 25);
    insertHeap(&heap, 30);
    insertHeap(&heap, 5);
    insertHeap(&heap, 100);

    traverseHeap(heap);

    int x = deleteHeap(&heap);
    printf("Deleted element is: %d\n", x);
    traverseHeap(heap);

    return 0;
}

