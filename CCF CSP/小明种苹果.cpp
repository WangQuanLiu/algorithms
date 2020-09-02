#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<limits>
#define MAX 1000
using namespace std;
int main() {
	int n, m, i, j, max = INT_MIN, temp, treeNumber=INT_MAX,tol=0;
	int** num, total[MAX]{ 0 }, fell[MAX]{ 0 };
	
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", (total + i));
		for (j = 0; j < m; j++) {
			scanf("%d", &temp);
			fell[i] += -temp;
		}
		tol += total[i] - fell[i];
	
		 if (max < fell[i]) {
			treeNumber = i;
			max =fell[i];
		}

	}
	printf("%d %d %d", tol, treeNumber+1, max);

	system("pause");
	return 0;
}
