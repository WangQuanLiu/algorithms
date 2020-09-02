#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<list>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int i,j;
	//vector<string>vec;
	vector<vector<int>>data;
	vector<vector<char>>symbol;
	string temp;
	for (i = 0; i < n; i++) {
		cin >> temp;
		vector<int>tempData;
		vector<char>tempSymbol;
		for (j = 0; j < temp.size(); j++) {
			if (isdigit(temp[j]))
				tempData.push_back(atoi(&temp[j]));
			else tempSymbol.push_back(temp[j]);
		}
		data.push_back(tempData);
		symbol.push_back(tempSymbol);
	}
	for (i = 0; i < symbol.size(); i++) {
		for (j = 0; j < symbol[i].size();) {
			if (symbol[i][j] == 'x') {
				data[i][j ] = data[i][j] * data[i][j+1];
				data[i].erase(data[i].begin() + j+1);
				symbol[i].erase(symbol[i].begin() + j);
			}
			else if (symbol[i][j] == '/') {
				data[i][j] = data[i][j] / data[i][j +1];
				data[i].erase(data[i].begin() + j+1);
				symbol[i].erase(symbol[i].begin() + j);
			}
			else j++;
		}
		for (j = 0; j < symbol[i].size(); ) {
			if (symbol[i][j] == '+') {
				data[i][j] = data[i][j] + data[i][j + 1];
				data[i].erase(data[i].begin() + j + 1);
				symbol[i].erase(symbol[i].begin() + j);
			}
			else {
				data[i][j] = data[i][j] - data[i][j + 1];
				data[i].erase(data[i].begin() + j + 1);
				symbol[i].erase(symbol[i].begin() + j);
			}
		}
		if (data[i][0] != 24) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}






	
	return 0;
}
