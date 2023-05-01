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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

unsigned char minimum = 255;
unsigned char maximum = 0;
float mean = -1.0;
int median = -1;


/**
 * @brief calculate statistics
 *
 * This function must be run first for other functions
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return void
 */
void calculate_statistics(unsigned char * ar, int size);


/**
 * @brief calculate statistics
 *
 * This function must be run first for other functions
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return void
 */
void print_statistics(unsigned char * ar, int size);


/**
 * @brief print the array
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return void
 */
void print_array(unsigned char * ar, int size);


/**
 * @brief sort the array
 *
 * This function must be run first for other functions
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return void
 */
void sort_array(unsigned char * ar, int size);


/**
 * @brief median value from the array
 *
 * if median is the default value, calculate_statistics() will be run in the function
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return int
 */
float find_median(unsigned char * ar, int size);


/**
 * @brief meam value from the array
 *
 * if mean is the default value, calculate_statistics() will be run in the function
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return float
 */
unsigned char find_mean(unsigned char * ar, int size);


/**
 * @brief maximum value from the array
 *
 * if maximum is the default value, calculate_statistics() will be run in the function
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return int
 */
unsigned char find_maximum(unsigned char * ar, int size);


/**
 * @brief minimum value from the array
 *
 * if minimum is the default value, calculate_statistics() will be run in the function
 *
 * @param ar   the array of unsigned char 
 * @param size the size of the array
 *
 * @return int
 */
unsigned char find_minimum(unsigned char * ar, int size);


#endif /* __STATS_H__ */
