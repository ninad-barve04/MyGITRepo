#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

void sort_selection(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        int mindata = arr[i];
        int min_idx = i;
        
        for(int j = i+1; j < size; j++) {
            if ( mindata > arr[j]) {
                mindata = arr[j];
                /*int d = arr[i];
                arr[i] = arr[j];
                arr[j] = d;    */ 
                min_idx = j;

            }
            

        }
        int d = arr[i];
        arr[i] = mindata;
        arr[min_idx] = d;
        printf("\n");
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        
    }
    return;
}



void sort_insertion(int *arr, int size) {
    int i = 0, j = 0;
    for (i = 0; i < size; i++) {
        j = i;
        while (j>0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j = j - 1;
        }
    }
}


void max_sort_selection(int *arr, int size) {
    for(int i = size-1; i >= 0; i--) {
        int mindata = arr[i];
        int min_idx = i;
        
        for(int j = size-i-1; j >= 0; j--) {
            if ( mindata < arr[j]) {
                mindata = arr[j];
                /*int d = arr[i];
                arr[i] = arr[j];
                arr[j] = d;    */ 
                min_idx = j;

            }
            

        }
        int d = arr[i];
        arr[i] = mindata;
        arr[min_idx] = d;
        printf("\n");
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        
    }
    return;
}

/*
void sort_list_bubble(List *list) {
    node *head = *list;
    node *temp = head;
    node *nextnode = temp->next;
    int swapped = 0;

    while (temp != NULL) {
        swapped = 0;
        temp = head;
        nextnode = temp->next;
        while (nextnode != NULL) {
            
            if (temp->data > nextnode->data) {
                int d = temp->data;
                temp->data = nextnode->data;
                nextnode->data = d;
                swapped = 1;
            }
            
            nextnode = nextnode->next;
            temp = temp->next;
          
        }
        if (swapped == 0) {
            break;
        }

    }
    return;
}*/