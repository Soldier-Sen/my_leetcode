#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* 48. 旋转图像
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

[i,j] -> [N-j-1][i]

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

tmp = p[0][0]
p[0][0] = p[3][0]
p[3][0] = p[3][3]
p[3][3] = p[0][3]
p[0][3] = tmp

提示：

matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000


*/

//由外层循环到内层循环旋转
void rotateMatrix1(int** matrix, int matrixSize, int* matrixColSize){
	int (*p)[matrixSize] = matrix; // leetcode 不能这样

	int j = 0, i = 0;
	for(i = 0; i < matrixSize / 2; i++) { //由外层循环到内层循环旋转
		for(j = i; j < matrixSize - i - 1; j++) {			
			int tmp = p[i][j];
			p[i][j] = p[matrixSize - j - 1][i];
			p[matrixSize - j - 1][i] = p[matrixSize - i - 1][matrixSize - j - 1];
			p[matrixSize - i - 1][matrixSize - j - 1] = p[j][matrixSize - i - 1];
			p[j][matrixSize - i - 1] = tmp;
		}
	}
}
void rotateMatrixTmp(int** matrix, int matrixSize, int* matrixColSize){	
	int j = 0, i = 0;
	for(i = 0; i < matrixSize / 2; i++) { //由外层循环到内层循环旋转
		for(j = i; j < matrixSize - i - 1; j++) {			
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[matrixSize - j - 1][i];
			matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
			matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
			matrix[j][matrixSize - i - 1] = tmp;
		}
	}
}

void rotateMatrix2(int** matrix, int matrixSize, int* matrixColSize)
{
	int (*p)[matrixSize] = matrix;
	
	for (int i = 0; i < matrixSize / 2; ++i) {
		for (int j = 0; j < (matrixSize + 1) / 2; ++j) {
			int temp = p[i][j];
			p[i][j] = p[matrixSize - j - 1][i];
			p[matrixSize - j - 1][i] = p[matrixSize - i - 1][matrixSize - j - 1];
			p[matrixSize - i - 1][matrixSize - j - 1] = p[j][matrixSize - i - 1];
			p[j][matrixSize - i - 1] = temp;
		}
	}
}

// 用翻转代替旋转
// 先水平翻转，再主对角线翻转。
void rotateMatrix(int** ma, int matrixSize, int* matrixColSize){
	int (*matrix)[matrixSize] = ma;

	//水平翻转
	for(int i = 0; i < matrixSize / 2; i++) {
		for(int j = 0; j < *matrixColSize; j++) {
			int temp  = matrix[i][j];
			matrix[i][j] = matrix[matrixSize - i - 1][j];
			matrix[matrixSize - i - 1][j] = temp;
		}
	}
	
	//主对角线翻转
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < i; j++) {
			int temp  = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}	
}


void rotateMatrixTestCase1(void)
{
	int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int matrixSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int matrixColSize = matrixSize;
	matrixPrint(matrix, matrixSize);
	rotateMatrix(matrix, matrixSize, &matrixColSize);
	printf("<<--------------->>\n");
	matrixPrint(matrix, matrixSize);
	printf("---------------\n");
}

void rotateMatrixTestCase2(void)
{
	int matrix[4][4] = {{5, 1, 9,11}, {2, 4, 8,10}, {13, 3, 6, 7}, {15,14,12,16}};
	int matrixSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int matrixColSize = matrixSize;
	matrixPrint(matrix, matrixSize);

	rotateMatrix(matrix, matrixSize, &matrixColSize);
	printf("<<--------------->>\n");
	matrixPrint(matrix, matrixSize);
	printf("---------------\n");
}

void rotateMatrixTestCase3(void)
{
	int matrix[5][5] = {{5, 1, 9, 11, 17}, 
						{2, 4, 8, 10, 18}, 
						{13, 3, 6, 7, 19}, 
						{15, 14, 12, 16, 20},
						{22, 24, 25, 23, 21},};
	int matrixSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int matrixColSize = matrixSize;
	matrixPrint(matrix, matrixSize);

	rotateMatrix(matrix, matrixSize, &matrixColSize);
	printf("<<--------------->>\n");
	matrixPrint(matrix, matrixSize);
	printf("---------------\n");
}

void rotateMatrixTest(void)
{
	rotateMatrixTestCase1();
	rotateMatrixTestCase2();
	rotateMatrixTestCase3();
}

