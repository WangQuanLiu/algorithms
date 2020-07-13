#include<iostream>
using namespace std;
const int maxn = 65;
int Tree[maxn];
/*
*/
inline int lowbit(int x) {
	return x&(-x);
}
/*
x为位置，value为值
功能：在x上加valus值 
*/
void add(int x, int value) {
	int i;
	for (i = x; i <= maxn; i += lowbit(i))//i+=lowbit(i)为找到i 的父结点，在二进制位中为10样式的位为 1 的父结点，具体有2是1,3的父结点，6是,5,7的父结点，100为010样式的父结点
		Tree[i]+=value;
}
/*
x为位置
功能：求数组从1~x前 n段之和
*/
int get(int x) {
	int sum = 0;
	int i = x;
	while (i > 0) {
		sum += Tree[i];
		i -= lowbit(i);//右结点减一可得到父结点，而左结点为0
	}
	
		
	return sum;
}
int main() {
	add(1, 2);
	add(3, 2);
	add(5, 2);
	printf("%d", get(8));
	system("pause");
	return 0;
}
