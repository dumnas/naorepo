Embedded Systems
Coursera assignment 1

https://www.coursera.org/learn/introduction-embedded-systems/peer/5hcJk/week-1-application-assignment

In the spec it says:

Most of the functions in the stats.c file require 2 input parameters and one return value:

	Input: A unsigned char pointer to an n-element data array
	Input: An unsigned integer as the size of the array
	Output: An unsigned char result from the function

I find it Output is unnecessary, and most of the functions return void.
You can always get the resulting array by the parameter, because it is passed by reference.
I believe this practice adds confusion and it does not improve the code readability.




