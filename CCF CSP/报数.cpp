#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;
inline bool isContainSeven(int num) {
	if (num % 7 == 0)return true;
	while (num) {
		if (num % 10==7)return true;
		num /= 10;
	}
	return false;
}
int main() {
	int man[4]{ 0 };
	int manCountiue[4]{ 0 };
	int n, cot = 0;
	scanf("%d", &n);
	int i,j=0;
	for (i = 1;; i++) {
		if (isContainSeven(i)) {
			manCountiue[j]++;
		}
		else {
			man[j]++;
		}
		if (man[0] + man[1] + man[2] + man[3] == n) {
			printf("%d\n%d\n%d\n%d\n", manCountiue[0], manCountiue[1], manCountiue[2], manCountiue[3]);
			break;
		}
		j = (j + 1) % 4;
	}




	
	return 0;
}
