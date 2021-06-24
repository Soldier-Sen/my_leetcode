#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* 56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 

提示：

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeInterlvals(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
	int (*newIntervals)[2];
	int newIntervalsSize = 0;
	newIntervals = malloc(intervalsSize);
	
	int i = 0;
	int j = 0;
	for(i = 0; i < intervalsSize; i++)  {
		for(j = 1; j < intervalsSize; j++) {
			if(intervals[i][1] >= intervals[j][0]) {
				newIntervals[newIntervalsSize][0] = intervals[i][0];
				newIntervals[newIntervalsSize][1] = intervals[j][1];
				newIntervalsSize++;
			}
			else {
				
			}
		}
	}
	return newIntervals;
}

void mergeInterlvalsTestCase1(void)
{
	int intervals[][2] = {{1,3},{2,6},{8,10},{15,18}};
	int rowNums = sizeof(intervals) / sizeof(intervals[0]);
	int colNums = sizeof(intervals[0]) / sizeof(intervals[0][0]);
	printf("rowNums = %d, colNums = %d, intervals=%p\n", rowNums, colNums, &intervals[1][0]);
	arrayTwoPrint(intervals, rowNums, colNums);
}

void mergeInterlvalsTest(void)
{
	mergeInterlvalsTestCase1();
}