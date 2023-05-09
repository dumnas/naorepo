/**
 * @file data.c 
 * @brief Some very basic data manipulation.
 *
 * @author Nao Takano
 * @date May 2023
 *
 */

#include <data.h>


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int count = 0;
	//char * reverse = (char*) malloc(DATA_SET_SIZE_W * sizeof(char));

	int large_enough = 20;
	uint8_t tmp[large_enough];
	uint8_t * reverse = tmp;
	if (ptr == NULL) {
		printf("malloc failed for reverse\n");
		return 1;
	}
	int32_t data_tmp = data;

	if (data < 0)
		data_tmp *= -1;
	
	while(data_tmp > 0) {

		int remainder = data_tmp % base;
		data_tmp /= base;

		//printf("%d ", remainder);
		char c;
		if (base <= 10) {
			c = remainder + '0';
		}
		else {
			if (remainder < 10)
				c = remainder + '0';
			else
				c = (remainder - 10) + 'A';
		}
		*reverse = c;
		reverse++;
		count++;
	}
	//printf("\n");
	*reverse = '\0';
	uint8_t * ptr_tmp = ptr;

	int count_sign = 0;
	if (data < 0) {
		*ptr_tmp = '-';
		ptr_tmp++;
		count_sign++;
	}
	
	for (int i = count; i > 0; i--) {
		reverse--;
		//printf("%c\n", *reverse);
		*ptr_tmp = *reverse;
		ptr_tmp++;
	}
	*ptr_tmp = '\0';
	
	return count + count_sign + 1;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int sign = 1;
	if (*ptr == '-')
		sign = -1;

	uint8_t * ptr_tmp = ptr;

	for (int i = 0; i < digits - 1; i++) {
		//printf("%c ", *ptr_tmp);
		ptr_tmp++;
	}
	//printf("\n");

	ptr_tmp--;

	int base_pow = 1;
	int32_t value = 0;

	printf("Before the loop %d\n", digits);

	for (int i = 0; i < digits - 1; i++) {

		if (*ptr_tmp == '-')
			break;

		int dec;
		if (*ptr_tmp >= 'A') {
			dec = *ptr_tmp - 'A' + 10;
		}
		else {
			dec = *ptr_tmp - '0';
		}

		value += dec * base_pow;
		//printf("%c, %d (%d)\n", *ptr_tmp, dec, base_pow);
		
		ptr_tmp--;
		base_pow *= base;	
	}

	return value * sign;
}
