/*
 * =====================================================================================
 *
 *       Filename:  array_sorting.c
 *
 *    Description: Array max min value output 
 *
 *        Version:  1.0
 *        Created:  15/12/21 11:42:47 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int main()
{
	int *p;
    int num, i;
    int input;

    printf("Enter length of array: ");
    scanf("%d", &num);
    printf("\n");

    p = (int *)malloc(sizeof(int) * num);

    printf("Enter numbers(integers) to add in array:\n");

    for (i = 0; i < num; i++) {
        scanf("%d", &input);
        *(p+i) = input;
    }


	int max = INT_MIN;
	int min = INT_MAX;
	for (i = 0; i < num; ++i) {
		if (p[i] > max){
			max = p[i];
		}
		if (p[i] < min) {
			min = p[i];
		}
	}
	
	printf("Max number is: %d\n", max);
	printf("Min number is: %d\n", min);
	return 0;
}
