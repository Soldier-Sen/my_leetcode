#include <stdio.h>
#include <stdlib.h>

/** 844. 比较含退格的字符串
 *	给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，
 	判断二者是否相等，并返回结果。 # 代表退格字符。
 *  
 	输入：S = "ab#c", T = "ad#c"
	输出：true
	解释：S 和 T 都会变成 “ac”。
 */

int backspaceCompare(char * s, char * t){
	int reslut = 1;
	int sLowIndex = 0, sFastIndex = 0;
	int tLowIndex = 0, tFastIndex = 0;
	while(s[sFastIndex] != '\0') {
		if(s[sFastIndex] != '#') {
			s[sLowIndex++] = s[sFastIndex];
		}
		else {
			sLowIndex--;
			sLowIndex = sLowIndex > 0 ? sLowIndex : 0;
		}
		sFastIndex++;
	}
	s[sLowIndex] = '\0';

	while(t[tFastIndex] != '\0') {
		if(t[tFastIndex] != '#') {
			t[tLowIndex++] = t[tFastIndex];
		}
		else {
			tLowIndex--;
			tLowIndex = tLowIndex > 0 ? tLowIndex : 0;
		}
		tFastIndex++;
	}	
	t[tLowIndex] = '\0';

	if(tLowIndex == sLowIndex) {
		sLowIndex = 0; tLowIndex = 0;
		while(s[sLowIndex] != '\0') {
			if(s[sLowIndex] != t[tLowIndex]) {
				reslut = 0;
			}
			sLowIndex++;
			tLowIndex++;
		}
	}
	else {
		reslut = 0;
	}
	
	return reslut;
}

void backspaceCompareTestCase1(void)
{
	char S[] = "ab#c", T[] = "ad#c";
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	int reslut = backspaceCompare(S, T);
	printf("reslut:%d\n", reslut);
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	printf("\n");
}

void backspaceCompareTestCase2(void)
{
	char S[] = "ab##", T[] = "c#d#";
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	int reslut = backspaceCompare(S, T);
	printf("reslut:%d\n", reslut);
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	printf("\n");
}

void backspaceCompareTestCase3(void)
{
	char S[] = "a##c", T[] = "#a#c";
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	int reslut = backspaceCompare(S, T);
	printf("reslut:%d\n", reslut);
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	printf("\n");
}

void backspaceCompareTestCase4(void)
{
	char S[] = "a#c", T[] = "b";
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	int reslut = backspaceCompare(S, T);
	printf("reslut:%d\n", reslut);
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	printf("\n");
}

void backspaceCompareTestCase5(void)
{
	char S[] = "a#cfdahfsj###", T[] = "b##dafjkljadf";
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	int reslut = backspaceCompare(S, T);
	printf("reslut:%d\n", reslut);
	printf("S:%s\n", S);
	printf("T:%s\n", T);
	printf("\n");
}


void backspaceCompareTest(void)
{
	backspaceCompareTestCase1();
	backspaceCompareTestCase2();
	backspaceCompareTestCase3();
	backspaceCompareTestCase4();
	backspaceCompareTestCase5();
}
