/**
 * @file main.c
 * @brief Main entry point to the final assessment
 *
 */

#include <platform.h>
#include <memory.h>
#include <course1.h>

#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];

int main(void)
{
#ifdef COURSE1
	course1();
#endif

	return 0;
}

