#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* 724. 寻找数组的中心下标
给你一个整数数组 nums，请编写一个能够返回数组 “中心下标” 的方法。
数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
如果数组不存在中心下标，返回 -1 。如果数组有多个中心下标，应该返回最靠近左边的那一个。
注意：中心下标可能出现在数组的两端。


示例 1：
输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 (1 + 7 + 3 = 11)，
右侧数之和 (5 + 6 = 11) ，二者相等。

示例 2：
输入：nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心下标。

示例 3：
输入：nums = [2, 1, -1]
输出：0
解释：
中心下标是 0 。
下标 0 左侧不存在元素，视作和为 0 ；
右侧数之和为 1 + (-1) = 0 ，二者相等。
 

提示：
nums 的长度范围为 [0, 10000]。
任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。

*/


// 暴力解法
// 假定中枢为i，分别计算中枢左右数组之和，然后进行对比。
// 缺点：每次移动中枢位置，右边数组都要清0重新计算。
int pivotIndex1(int* nums, int numsSize){
    int lSum = 0, rSum = 0;
    int i = 0, j = 0;
    for(i = 0; i < numsSize; i++) {
        if(i == 0) lSum = 0;
        else lSum += nums[i - 1];
        rSum = 0;
        for(j = i + 1; j < numsSize; j++) {
            rSum += nums[j];
        }
        if(rSum == lSum) {
            return i;
        }
    }
    return -1;
}


int pivotIndex(int* nums, int numsSize){
    int lSum = 0, rSum = 0;
    int i = 0, j = 0;
    for(i = 0; i < numsSize; i++) {
        if(i == 0) { 
			lSum = 0;
			for(j = 1; j < numsSize; j++) {
				rSum += nums[j];
			}
        }
        else {
			lSum += nums[i - 1];
			rSum -= nums[i];
        }
		
		if(rSum == lSum) {
			return i;
		}
    }
    return -1;
}


void pivotIndexTestCase1(void)
{
	int nums[] = {1, 7, 3, 6, 5, 6};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayPrint(nums, numsSize);
	int index = pivotIndex(nums, numsSize);
	printf("%s index = %d\n", __func__, index);
}
void pivotIndexTestCase2(void)
{
	int nums[] = {1, 2, 3};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayPrint(nums, numsSize);
	int index = pivotIndex(nums, numsSize);
	printf("%s index = %d\n", __func__, index);
}
void pivotIndexTestCase3(void)
{
	int nums[] = {2, 1, -1};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayPrint(nums, numsSize);
	int index = pivotIndex(nums, numsSize);
	printf("%s index = %d\n", __func__, index);
}


void pivotIndexTestCase4(void)
{
	int nums[] = {-1,-1,-1,-1,-1,-1};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayPrint(nums, numsSize);
	int index = pivotIndex(nums, numsSize);
	printf("%s index = %d\n", __func__, index);
}

void pivotIndexTest(void)
{
	pivotIndexTestCase1();
	pivotIndexTestCase2();
	pivotIndexTestCase3();
	pivotIndexTestCase4();
}

