#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>


int g_prices[] = {1, 2, 3, 4, 5};
//int g_prices[] = {7,1,5,3,6,4};
//int g_prices[] = {7,1,5,3,6,4};

/* 动态规划
i = 1
dp[1][0] = FMAX(dp[0][0], dp[0][1] + prices[1]) = (0, -7+1) = -6
dp[1][1] = FMAX(dp[0][1], dp[0][0] - prices[1]) = (-7, 0-1) = -1

i = 2
dp[2][0] = FMAX(dp[1][0], dp[1][1] + prices[2]) = (-6, -1+5) = 4
dp[2][1] = FMAX(dp[1][1], dp[1][0] - prices[2]) = (-1, -6-5)  =-1

i = 3
dp[3][0] = FMAX(dp[2][0], dp[2][1] + prices[3]) = (4, -1+3) = 4
dp[3][1] = FMAX(dp[2][1], dp[2][0] - prices[3]) = (-1, 4-3) = 1

i = 4
dp[4][0] = FMAX(dp[3][0], dp[3][1] + prices[4]) = (4, 1+6) = 7
dp[4][1] = FMAX(dp[3][1], dp[3][0] - prices[4]) = (1, 4-6) = 1

i = 5
dp[5][0] = FMAX(dp[4][0], dp[4][1] + prices[5]) = (7, 1+4) = 7
dp[5][1] = FMAX(dp[4][1], dp[4][0] - prices[5]) = (1, 7-4) = 3

*/
int maxProfit(int* prices, int pricesSize){
	if(!prices || pricesSize < 2) return 0;
	
#define FMAX(a, b) ((a) > (b) ? (a) : (b))
	int dp[pricesSize][2];
	dp[0][0] = 0, dp[0][1] = -prices[0];
	for (int i = 1; i < pricesSize; ++i) {
		dp[i][0] = FMAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = FMAX(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	printf("%d\n", dp[pricesSize - 1][0]);
	return dp[pricesSize - 1][0];
}

int maxProfit2(int* prices, int pricesSize){
	if(!prices || pricesSize < 2) return 0;

	int i;
	int profit = 0;
	for(i = 0; i < pricesSize; i++)
	{
		if(prices[i] < prices[i+1])
		{
			profit += prices[i+1] - prices[i];
		}
	}
	printf("profit = %d\n", profit);
	return profit;
}


int main(int argc, char *argv[])
{
	//removeDuplicatesTest();
	//backspaceCompareTest();
	//sortedSquaresTest();
	minSubArrayLenTest();
	//maxProfit2((int *)&g_prices, sizeof(g_prices)/sizeof(g_prices[0]));

	return 0;
}

