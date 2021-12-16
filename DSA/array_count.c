/*
 * =====================================================================================
 *
 *       Filename:  array_count.c
 *
 *    Description:  Count number of times an input number is present in a given array
 *
 *        Version:  1.0
 *        Created:  16/12/21 09:53:42 PM IST
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

int main(void)
{
	int *arr;
	int i, len, num, input, count = 0;

	printf("Enter length of array: ");
	scanf("%d", &len);
	printf("\n");

	arr = (int *)malloc(sizeof(int) * len);

	printf("Enter numbers(integers) to add in array:\n");

    for (i = 0; i < len; i++) {
        scanf("%d", &input);
        *(arr+i) = input;
    }

	printf("Enter number to count in array: ");
	scanf("%d", &num);

	for (i = 0; i < len; ++i) {
		if (arr[i] == num) {
			count = count + 1;
		}
	}
	
	printf("The number %d occurs %d times in given array.\n", num, count);

	return 0;
}
