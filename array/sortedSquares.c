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


// 方法一：直接排序
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


//方法二：分成正负两个数组进行处理
int *sortedSquares2(int *nums, int numsSize, int *returnSize) 
{
	int firstNegativeIndex = -1;
	int l = 0, r = numsSize - 1;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(nums[mid] < 0) {
			firstNegativeIndex = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	int newSize = 0;
	int *newNums = (int *)malloc(numsSize * sizeof(int));
	l = firstNegativeIndex;
	r = firstNegativeIndex + 1;
	while(l >= 0 || r < numsSize) {
		if(l < 0) { //左边数据没有，按顺序放右边数据。
			newNums[newSize++] = nums[r] * nums[r];
			r++;
		}
		else if(r == numsSize) {
			newNums[newSize++] = nums[l] * nums[l];
			l--;
		}
		else if(nums[r] * nums[r] > nums[l] * nums[l]) {
			newNums[newSize++] = nums[l] * nums[l];
			l--;
		}
		else {
			newNums[newSize++] = nums[r] * nums[r];
			r++;
		}
	}
	*returnSize = newSize;
	return newNums;
}

//方法三：双指针，但指针分别指向头和尾, 比较头和尾的平方，大的逆序放入新数组中。
int *sortedSquares3(int *nums, int numsSize, int *returnSize) {
	int *newNums = (int *)malloc(numsSize * sizeof(int));

	int l = 0;
	int r = numsSize - 1;
	int pos = r;
	while(l < r) {
		int lValue = nums[l] * nums[l];
		int rValue = nums[r] * nums[r];
		if(lValue > rValue) {
			newNums[pos] = lValue;
			l++;
		}
		else {
			newNums[pos] = rValue;
			r--;
		}
		pos--;
	}

	*returnSize = numsSize;
	return newNums;	
}


void sortedNumsPrint(int *nums, int numsSize)
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
	int nums[] = {-9,-8,-6,-4,-1,0,3,10};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	sortedNumsPrint(nums, numsSize);
	int *newNums = sortedSquares3(nums, numsSize, &numsNewSize);
	sortedNumsPrint(newNums, numsNewSize);
	free(newNums);
}

void sortedSquaresTestCase2(void)
{
	int nums[] = {-7,-3,2,3,11};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	sortedNumsPrint(nums, numsSize);
	int *newNums = sortedSquares3(nums, numsSize, &numsNewSize);
	sortedNumsPrint(newNums, numsNewSize);
	free(newNums);
}

void sortedSquaresTestCase3(void)
{
	int nums[] = {2,3,6,11};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	sortedNumsPrint(nums, numsSize);
	int *newNums = sortedSquares3(nums, numsSize, &numsNewSize);
	sortedNumsPrint(newNums, numsNewSize);
	free(newNums);
}

void sortedSquaresTestCase4(void)
{
	int nums[] = {-4,-1,0,3,10};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int numsNewSize = 0;
	sortedNumsPrint(nums, numsSize);
	int *newNums = sortedSquares3(nums, numsSize, &numsNewSize);
	sortedNumsPrint(newNums, numsNewSize);
	free(newNums);
}


void sortedSquaresTest(void)
{
	sortedSquaresTestCase1();
	sortedSquaresTestCase2();
	sortedSquaresTestCase3();
	sortedSquaresTestCase4();
}

