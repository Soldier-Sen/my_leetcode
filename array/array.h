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




inline void arrayAndTargetPrint(int *nums, int numsSize, int target)
{
	int i = 0;
	for(i = 0; i < numsSize && nums; i++)
	{
		if(i == 0) printf("%d [%d,", target, nums[i]);
		else if(i == numsSize - 1) printf("%d]\n", nums[i]);
		else printf("%d,", nums[i]);
	}
}

void arrayTwoPrint(int **nums, int rowNums, int colNums)
{
	int (*p)[colNums] = nums;
	int i = 0;
	printf("{");
	for(i = 0; i < rowNums; i++)
	{
		for(int j = 0; j < colNums; j++)
		{
			if(j == 0) printf("{%d,", p[i][j]);
			else if(j == colNums - 1) printf("%d}", p[i][j]);
			else printf("%d,", p[i][j]);
		}
		printf(",");
	}
	printf("}\n");
}

inline void matrixPrint(int **matrix, int matrixSize)
{
	int (*p)[matrixSize] = matrix; //需要转换，不然直接访问matrix在64位机不能正确访问。
	
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < matrixSize; j++) {
			if(j == 0)printf("{%d,", p[i][j]);
			else if(j == matrixSize - 1) printf("%d}", p[i][j]);
			else printf("%d,", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

#endif

