#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "array.h"

/** 209.长度最小的子数组
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
 * 并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 *	输入：target = 7, nums = [2,3,1,2,4,3]
 *	输出：2
 *  解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 */

int minSubArrayLen1(int target, int *nums, int numsSize) {
	int minLen = 0;
	int sum = 0;
	int i = 0, j = 0;
	for(i = 0; i < numsSize; i++) {
		sum = 0;
		for(j = i; j < numsSize; j++) {
			sum += nums[j];
			if(sum >= target) {
				if(minLen == 0 || (j - i + 1) < minLen) {
					printf("i = %d, j = %d\n", i, j);
					minLen = j - i + 1;
				}
				break;
			}
		}
	}
	return minLen;
}
//快慢指针
int minSubArrayLen2(int target, int* nums, int numsSize){
	int minLen = 0;
	int sum = 0;
	int lWin = 0, rWin = 0;
	while(rWin < numsSize) {
		sum = 0;
		for(int i = lWin; i <= rWin; i++) {
			sum += nums[i];
		}
		if(sum >= target) {
			int sumLen = rWin - lWin + 1;
			if(minLen == 0 || sumLen < minLen) {
				minLen = sumLen;
			}
			lWin++;
		}
		else {
			rWin++;
		}
	}
	return minLen;
}


//滑动窗口
//就是不断的调节子序列的起始位置和终止位置
int minSubArrayLen(int target, int *nums, int numsSize) {
	int minLen = 0;
	int sum = 0;
	int lWin = 0, rWin = 0;
	while(rWin < numsSize) {
		sum += nums[rWin];
		while(sum >= target) {
			int sumLen = rWin - lWin + 1;
			if(minLen == 0 || sumLen < minLen) {
				minLen = sumLen;
			}
			sum -= nums[lWin++]; //滑动窗口的精髓
		}
		rWin++;
	}
	return minLen;
}


void minSubArrayLenTestCase1(void)
{
	int nums[] = {2,3,1,2,4,3};
	int target = 7;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(target, nums, numsSize);
	int result = minSubArrayLen(target, nums, numsSize);
	printf("%s result = %d\n", __func__, result);
}

void minSubArrayLenTestCase2(void)
{
	int nums[] = {1,4,4};
	int target = 4;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(target, nums, numsSize);
	int result = minSubArrayLen(target, nums, numsSize);
	printf("%s result = %d\n", __func__, result);
}

void minSubArrayLenTestCase3(void)
{
	int nums[] = {1,1,1,1,1,1,1,1};
	int target = 11;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(target, nums, numsSize);
	int result = minSubArrayLen(target, nums, numsSize);
	printf("%s result = %d\n", __func__, result);
}

void minSubArrayLenTestCase4(void)
{
	int nums[] = {9,8,4,3,1, 3, 6, 10};
	int target = 20;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(target, nums, numsSize);
	int result = minSubArrayLen(target, nums, numsSize);
	printf("%s result = %d\n", __func__, result);
}


void minSubArrayLenTest(void)
{
	minSubArrayLenTestCase1();
	minSubArrayLenTestCase2();
	minSubArrayLenTestCase3();
	minSubArrayLenTestCase4();
}

