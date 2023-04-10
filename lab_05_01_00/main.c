#include <stdio.h>
#include <stdlib.h>
#include "max_pos_after_neg.h"

int main(void)
{
	int max;
	int error;
	
	error = process(stdin, &max);
	if (error == IO_ERR)
	{
		printf("There are no numbers");
		return EXIT_FAILURE;
	}
	if (error == NO_POS_NUMS)
	{
		printf("There are no positive numbers");
		return EXIT_FAILURE;
	}
	
	printf("Result: %d\n", max);
	
	return EXIT_SUCCESS;
}
