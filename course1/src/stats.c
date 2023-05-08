/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Coursea Assignment Week 1
 *
 * https://www.coursera.org/learn/introduction-embedded-systems/peer/5hcJk/week-1-application-assignment
 *
 * @author Nao Takano
 * @date   5/1/2023
 *
 */



#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


// void main() {

//   unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                               114, 88,   45,  76, 123,  87,  25,  23,
//                               200, 122, 150, 90,   92,  87, 177, 244,
//                               201,   6,  12,  60,   8,   2,   5,  67,
//                                 7,  87, 250, 230,  99,   3, 100,  90};

//   /* Other Variable Declarations Go Here */

//   calculate_statistics(test, SIZE);
  
//   /* Statistics and Printing Functions Go Here */
//   print_array(test, SIZE);
//   print_statistics(test, SIZE);
// }


void print_array(unsigned char * ar, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%2d: %d\n", i, ar[i]);
	}
}


int comp(const void *a, const void *b)
{
	//return (*(unsigned char*)a - *(unsigned char*)b); // ascending order
	return (*(unsigned char*)b - *(unsigned char*)a); // descending order
}


void sort_array(unsigned char * ar, int size)
{
	qsort(ar, size, sizeof(unsigned char), comp);
	for (int i = 0; i < size; i++)
		printf("%2d: %d\n", i, ar[i]);
}


void calculate_statistics(unsigned char * ar, int size)
{
	int total = 0;
	int i = 0;
	
	for (; i < size; i++) {
		unsigned char value = ar[i];

		if (value > maximum)
			maximum = value;
		else if (value < minimum)
			minimum = value;

		total += value;
	}

	assert(i == size);

	mean = (float)total / size;
	sort_array(ar, size);
	median = ar[size / 2];
}


void print_statistics(unsigned char * ar, int size)
{	
	printf("minimum: %d\n", minimum);
	printf("maximum: %d\n", maximum);
	printf("mean   : %f\n", mean);
	printf("median : %d\n", median);

}


float find_median(unsigned char * ar, int size)
{
	if (median == -1)
		calculate_statistics(ar, size);
	
	return median;
}

unsigned char find_mean(unsigned char * ar, int size)
{
	if (mean == -1.0)
		calculate_statistics(ar, size);
		
	return mean;
}

unsigned char find_maximum(unsigned char * ar, int size)
{
	if (maximum == 0)
		calculate_statistics(ar, size);

	return maximum;
}

unsigned char find_minimum(unsigned char * ar, int size)
{
	if (minimum == 255)
		calculate_statistics(ar, size);

	return minimum;
}

