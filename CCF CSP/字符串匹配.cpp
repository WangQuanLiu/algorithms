#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#define MAX 150
using namespace std;
void getArray(int*f, string&ch) {
	f[0] = f[1] = 0;
	int j;
	int m = ch.length();
	for (int i = 1; i < m; i++) {
		j = f[i];
		while (j&&ch[i] != ch[j])j = f[j];
		f[i + 1] = f[i] == f[j] ? j + 1 : 0;
	}
}
bool kmp(int*f, string&source, string&match) {
	int n = source.length(), m =match.length();
	getArray(f, source);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j&&source[i] != match[j])j = f[j];
		if (source[i] == match[j])j++;
		if (j == m)return true;
	}
	return false;
}
int main() {
	int f[MAX]{ 0 };
	//char source[MAX];
	string source;
	vector<string>vec,save;
	cin >> source;
	int flag,n;
	getchar();
//	getchar();
	scanf("%d", &flag);
	string temp;
	getchar();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
		getchar();
		//getchar();
	}
	save = vec;
	if (flag == 0) {
		temp = source;
		source.clear();
		for (int i = 0; i < temp.size(); i++) {
			source += tolower(temp[i]);
		}
		for (int i = 0; i < vec.size(); i++) {
			temp = vec[i];
			vec[i].clear();
			for (int j = 0; j < temp.size(); j++) {
				vec[i] += tolower(temp[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (kmp(f,vec[i], source)) {
			cout << save[i] << endl;
		}
	}
	//scanf("%s", match);
	//cout << kmp(f, match, source);





	return 0;
}
