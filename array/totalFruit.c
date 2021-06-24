#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
在一排树中，第 i 棵树产生 tree[i] 型的水果。
你可以从你选择的任何树开始，然后重复执行以下步骤：

把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
请注意，在选择一颗树后，你没有任何选择：
	你必须执行步骤 1，然后执行步骤 2，
	然后返回步骤 1，然后执行步骤 2，
	依此类推，直至停止。

你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。

用这个程序你能收集的水果树的最大总量是多少？

 

示例 1：

输入：[1,2,1]
输出：3
解释：我们可以收集 [1,2,1]。
示例 2：

输入：[0,1,2,2]
输出：3
解释：我们可以收集 [1,2,2]
如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
示例 3：

输入：[1,2,3,2,2]
输出：4
解释：我们可以收集 [2,3,2,2]
如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
示例 4：

输入：[3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：我们可以收集 [1,2,1,1,2]
如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 棵水果树。

提示：

1 <= tree.length <= 40000
0 <= tree[i] < tree.length


*/

int totalFruit(int* tree, int treeSize){
	if(treeSize < 3) return treeSize;
	
	int maxFruitNum = 2;
	int basket[2];
	int i = 0, j = 0;

	for(i = 1; i < treeSize; i++) {
		basket[0] = tree[i-1];
		basket[1] = tree[i];
		int maxFruitNumTmp = 2;
		for(j = i + 1; j < treeSize; j++) {
			if(basket[0] != tree[j] && basket[1] != tree[j]) {
				break;
			}
			maxFruitNumTmp++;
			if(maxFruitNumTmp > maxFruitNum) maxFruitNum = maxFruitNumTmp;
		}
	}

	return maxFruitNum;
}


void fruitPrint(int *tree, int numsSize)
{
	int i = 0;
	for(i = 0; i < numsSize && tree; i++)
	{
		if(i == 0) printf("[%d,", tree[i]);
		else if(i == numsSize - 1) printf("%d]\n", tree[i]);
		else printf("%d,", tree[i]);
	}
}



void totalFruitTestCase1(void)
{
	int tree[] = {1,2,1};
	int treeSize = sizeof(tree) / sizeof(tree[0]);
	fruitPrint(tree, treeSize);
	int num = totalFruit(tree, treeSize);
	printf("%s num = %d\n", __func__, num);
}

void totalFruitTestCase2(void)
{
	int tree[] = {0,1,2,2};
	int treeSize = sizeof(tree) / sizeof(tree[0]);
	fruitPrint(tree, treeSize);
	int num = totalFruit(tree, treeSize);
	printf("%s num = %d\n", __func__, num);
}

void totalFruitTestCase3(void)
{
	int tree[] = {1,2,3,2,2};
	int treeSize = sizeof(tree) / sizeof(tree[0]);
	fruitPrint(tree, treeSize);
	int num = totalFruit(tree, treeSize);
	printf("%s num = %d\n", __func__, num);
}

void totalFruitTestCase4(void)
{
	int tree[] = {3,3,3,1,2,1,1,2,3,3,4};
	int treeSize = sizeof(tree) / sizeof(tree[0]);
	fruitPrint(tree, treeSize);
	int num = totalFruit(tree, treeSize);
	printf("%s num = %d\n", __func__, num);
}

void totalFruitTestCase5(void)
{
	int tree[] = {0,0,1,1};
	int treeSize = sizeof(tree) / sizeof(tree[0]);
	fruitPrint(tree, treeSize);
	int num = totalFruit(tree, treeSize);
	printf("%s num = %d\n", __func__, num);
}


void totalFruitTest(void)
{
	totalFruitTestCase1();
	totalFruitTestCase2();
	totalFruitTestCase3();
	totalFruitTestCase4();
	totalFruitTestCase5();
}

