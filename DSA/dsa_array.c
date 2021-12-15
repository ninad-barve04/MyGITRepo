/*
 * =====================================================================================
 *
 *       Filename:  dsa_array.c
 *
 *    Description:  array practice
 *
 *        Version:  1.0
 *        Created:  12/12/21 11:01:19 PM IST
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
	
	for (i = 0; i < num ; i++) {
		printf("p[%d] = %d\n", i, p[i]);
	}
	return 0;
}
