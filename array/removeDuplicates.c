#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
题目：删除有序数组中的重复项
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

提示：

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按升序排列

说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。


------解题思路-----
解法： 双指针
首先注意数组是有序的，那么重复的元素一定会相邻。
要求删除重复元素，实际上就是将不重复的元素移到数组的左侧。
考虑用 2 个指针，一个在前记作 p，一个在后记作 q，算法流程如下：
1.比较 p 和 q 位置的元素是否相等。
如果相等，q 后移 1 位
如果不相等，将 q 位置的元素复制到 p+1 位置上，p 后移一位，q 后移 1 位
重复上述过程，直到 q 等于数组长度。

返回 p + 1，即为新数组长度。

*/

int removeDuplicates(int* nums, int numsSize){
	if(!nums || numsSize == 0) return 0;

	int i = 0, j = 0;
	for(j = 1; j < numsSize; j++)
	{
		if(nums[i] != nums[j])
		{
			nums[++i] = nums[j];
		}
	}
	return i+1;;
}


void removeDuplicatesTestCase1(void)
{
	int nums[] = {0,0,0,0,0,0,0,0,0,1,1,1,2,2,3,3,4};
	int newSize = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
	
	for(int i = 0; i < newSize; i++)
		printf("%d ", nums[i]);
	printf("\n");
}

void removeDuplicatesTestCase2(void)
{

}

void removeDuplicatesTestCase3(void)
{

}

void removeDuplicatesTest(void)
{
	removeDuplicatesTestCase1();
	removeDuplicatesTestCase2();
	removeDuplicatesTestCase3();
}


