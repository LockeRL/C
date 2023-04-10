#include "max_pos_after_neg.h"

int process(FILE *f, int *max)
{
	int prev, cur;
	bool flag = false;
	if (fscanf(f, "%d", &prev) == 1)
		while (fscanf(f, "%d", &cur) == 1)
		{
			if (cur > 0 && prev < 0)
			{
				if (flag)
				{
					if (cur > *max)
						*max = cur;
				}
				else
				{
					*max = cur;
					flag = true;
				}
			}
			prev = cur;
		}
	else 
		return IO_ERR;
	if (!flag)
		return NO_POS_NUMS;
	return 0;
}
