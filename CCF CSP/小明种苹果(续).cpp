#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX 1000
using namespace std;
int main() {
	int n,i,j,fallTreeCount=0,appleCount=0,appleGroupCount=0;
	int**num,size[MAX];
	num = (int**)malloc(sizeof(int*)*MAX);
	for (i = 0; i < MAX; i++) {
		num[i] = (int*)malloc(sizeof(int)*MAX);
		memset(num[i], 0, MAX);
	}
	scanf("%d", &n);
	bool isFall[MAX]{ false };
	int index = 0;
	for (i = 0; i < n; i++,index++) {
		scanf("%d", &size[i]);
		bool flag = false;
		int isFallSum = 0;
		int cot = 0;
		
		scanf("%d", &num[i][0]);
		isFallSum = num[i][0];
		cot= num[i][0];
		for (j = 1; j < size[i]; j++) {
			scanf("%d", &num[i][j]);
			if (!flag) {
				if (num[i][j] <= 0) {
					isFallSum =isFallSum+ num[i][j];
				}
				else {
					if (isFallSum != num[i][j])
						flag = true;
				}
			}
			if (num[i][j] > 0) {
				cot = num[i][j];
			}
			else
				cot += num[i][j];
		}
		appleCount += cot;
		if (flag) {
			fallTreeCount++;
			isFall[index] = true;
		}
	}
	if (n < 3) {
		printf("%d %d %d", appleCount, fallTreeCount, 0);
	}
	else if (n == 3) {
		printf("%d %d %d", appleCount, fallTreeCount, isFall[0] && isFall[1] && isFall[2]);
	}
	else {
		for (i = 0; i < n; i++) {
			int temp;
			if (i == 0) {
				temp = (isFall[0] && isFall[n - 1] && isFall[1]) ? 1 : 0;
				appleGroupCount += temp ;
			}
			else if (i == n - 1) {
				temp = isFall[n - 2] && isFall[n - 1] && isFall[0] ? 1 : 0;
				appleGroupCount +=temp ;
			}
			else {
				temp = isFall[i - 1] && isFall[i] && isFall[i + 1] ? 1 : 0;
				appleGroupCount +=temp ;
			}
		}
		printf("%d %d %d", appleCount, fallTreeCount, appleGroupCount);
	}


	system("pause");
	return 0;
}
