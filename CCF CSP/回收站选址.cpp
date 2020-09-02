#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<list>
struct Type {
	int x, y;
	Type(){}
	Type(const int&x, const int &y) {
		this->x = x;
		this->y = y;
	}
	friend bool operator<(const Type&obj1,const Type&obj2) {
		if (obj1.x == obj2.x)return obj1.y < obj2.y;
		return obj1.x < obj2.x;
	}
};
using namespace std;
int main() {
	map<Type,bool>m;
	list<Type>ls;
	int n;
	int countArray[5]{ 0 };
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		Type temp;
		scanf("%d %d", &temp.x, &temp.y);
		ls.push_back(temp);
		m[temp] = true;
	}
	for (list<Type>::iterator iter = ls.begin(); iter != ls.end(); iter++) {
		Type temp = *iter;
		if (m[Type(temp.x, temp.y + 1)] &&
			m[Type(temp.x, temp.y - 1)] && 
			m[Type(temp.x + 1, temp.y)] &&
			m[Type(temp.x - 1, temp.y)]) {

			int level = 0;
			if (m[Type(temp.x - 1, temp.y - 1)])level++;
			if (m[Type(temp.x - 1, temp.y + 1)])level++;
			if (m[Type(temp.x + 1, temp.y + 1)])level++;
			if (m[Type(temp.x + 1, temp.y - 1)])level++;
			countArray[level]++;

		}
	}
	for (int i = 0; i < 5; i++)
		printf("%d\n", countArray[i]);






	return 0;
}
