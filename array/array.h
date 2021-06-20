#ifndef _ARRAY_H_
#define _ARRAY_H_

inline void arrayPrint(int *nums, int numsSize)
{
	int i = 0;
	for(i = 0; i < numsSize && nums; i++)
	{
		if(i == 0) printf("[%d,", nums[i]);
		else if(i == numsSize - 1) printf("%d]\n", nums[i]);
		else printf("%d,", nums[i]);
	}
}

#endif

