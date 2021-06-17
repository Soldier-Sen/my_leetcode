#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


/** 977.有序数组的平方
 * 给你一个按 非递减顺序 排序的整数数组 nums，
 * 返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 *	输入：nums = [-4,-1,0,3,10]
 *	输出：[0,1,9,16,100]
 */


int* sortedSquares(int* nums, int numsSize, int* returnSize){
	int *newNums = (int *)malloc(numsSize * sizeof(int));
	
	int i = 0, j = 0;
	//先计算
	while(i < numsSize) {
		newNums[j] = nums[i] * nums[i];
		i++; j++;
	}
	//再排序
	for(i = 0; i < numsSize; i++) {
		for(j = i + 1; j < numsSize; j++) {
			if(newNums[i] > newNums[j]) {
				int x = newNums[i];
				newNums[i] = newNums[j];
				newNums[j] = x;
			}
		}
	}
	*returnSize = numsSize;
	return newNums;
}

void numsPrint(int *nums, int numsSize)
{
	int i = 0;
	for(i = 0; i < numsSize && nums; i++)
	{
		if(i == 0) printf("[%d,", nums[i]);
		else if(i == numsSize - 1) printf("%d]\n", nums[i]);
		else printf("%d,", nums[i]);
	}

}
void sortedSquaresTestCase1(void)
{
	int nums[] = {-4,-1,0,3,10};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	numsPrint(nums, numsSize);
	int *newNums = sortedSquares(nums, numsSize, &numsNewSize);
	numsPrint(newNums, numsNewSize);
	free(newNums);
}

void sortedSquaresTestCase2(void)
{
	int nums[] = {-7,-3,2,3,11};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	numsPrint(nums, numsSize);
	int *newNums = sortedSquares(nums, numsSize, &numsNewSize);
	numsPrint(newNums, numsNewSize);
	free(newNums);
}

void sortedSquaresTestCase3(void)
{
	int nums[] = {2,3,6,11};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	numsPrint(nums, numsSize);
	int *newNums = sortedSquares(nums, numsSize, &numsNewSize);
	numsPrint(newNums, numsNewSize);
	free(newNums);
}


void sortedSquaresTest(void)
{
	sortedSquaresTestCase1();
	sortedSquaresTestCase2();
	sortedSquaresTestCase3();
}

