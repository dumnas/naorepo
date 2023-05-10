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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdio.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}



uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{		
	uint8_t tmp[length];

	uint8_t * p_src = src;
	uint8_t * p_tmp = tmp;
	
	for (int i = 0; i < length; i++) {
		//printf("%d | ", *p_src);
		*p_tmp++ = *p_src++;
	}

	p_tmp = tmp;
	uint8_t * p_dst = dst;
	
	dst = (uint8_t *) malloc (sizeof(uint8_t) * length);
	if (dst == NULL) {
		printf("Not enough memory (my_memmove)\n");
		return NULL;
	}
	for (int i = 0; i < length; i++) {
		*p_dst++ = *p_tmp++;
	}
	
	return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
	uint8_t * p_src = src;
	uint8_t * p_dst = dst;

	for (int i = 0; i < length; i++) {
		*p_dst++ = *p_src++;
	}

	return dst;
}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	uint8_t * src_tmp = src;
	for (int i = 0; i < length; i++)
		*src_tmp++ = value;
	
	return src;
}


uint8_t * my_memzero(uint8_t * src, size_t length)
{
	uint8_t * src_tmp = src;
	for (int i = 0; i < length; i++)
		*src_tmp++ = 0;

	return src;
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{
	uint8_t * p_src = src;
	for (int i = 0; i < length; i++) {
		//printf("before %2d: %d\n", i, *p_src);
		p_src++;
	}

	uint8_t * p_end = p_src;
	p_end--;
	p_src = src;             // reset
	
	for (int i = 0; i < length / 2; i++) {
		uint8_t tmp = *p_src;
		*p_src++ = *p_end;
		*p_end-- = tmp;
	}

	p_src = src;
	printf("\n");
	for (int i = 0; i < length; i++) {
		//printf("after %3d: %d\n", i, *p_src);
		p_src++;
	}
	return src;
}


int32_t * reserve_words(size_t length)
{
	int32_t * p = (int32_t *)malloc(length * sizeof(int32_t) );
	if (p == NULL) {
		printf("Not enough memory\n");
		return NULL;
	}

	return p;
}


void free_words(uint32_t * src)
{
	free(src);
}
