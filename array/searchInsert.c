#include <stdio.h>
#include <stdlib.h>
#include "array.h"


/* 35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

*/


int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    while(left <=  right){
        int middle = left + (right - left) / 2;
        if(target > nums[middle]) {
            left = middle + 1;
        }
        else if(target < nums[middle]) {
            right = middle - 1;
        }
        else {
            return middle;
        }
    }
    return left;
}


void searchInsertTestCase1(void)
{
	int nums[] = {1, 3, 5, 6};
	int target = 5;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(nums, numsSize, target);
	int index = searchInsert(nums, numsSize, target);
	printf("%s index = %d\n", __func__, index);
}

void searchInsertTestCase2(void)
{
	int nums[] = {1, 3, 5, 6};
	int target = 2;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(nums, numsSize, target);
	int index = searchInsert(nums, numsSize, target);
	printf("%s index = %d\n", __func__, index);
}

void searchInsertTestCase3(void)
{
	int nums[] = {1, 3, 5, 6};
	int target = 7;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(nums, numsSize, target);
	int index = searchInsert(nums, numsSize, target);
	printf("%s index = %d\n", __func__, index);
}

void searchInsertTestCase4(void)
{
	int nums[] = {1, 3, 5, 6};
	int target = 0;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	arrayAndTargetPrint(nums, numsSize, target);
	int index = searchInsert(nums, numsSize, target);
	printf("%s index = %d\n", __func__, index);
}

void searchInsertTest(void)
{
	searchInsertTestCase1();
	searchInsertTestCase2();
	searchInsertTestCase3();
	searchInsertTestCase4();
}

