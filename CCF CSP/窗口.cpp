#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 10
using namespace std;
struct Coor {
	Coor() {}
	int x1, y1, x2, y2;
	int num, level;
	 bool operator<(const Coor&obj) {
		 return this->level < obj.level;
	}
	
};
struct Click {
	int x, y;
};
inline void setLevel(vector<Coor>&vec, int num) {
	for (int i = 0; i < num; i++) {
		vec[i].level++;
	}
	vec[num].level = 1;
}
int main() {
	int N, M, i, j;
	vector<Coor>coor;
	vector<string>input;
	//vector<Click>click;
//	int level[MAX];
	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++) {
		Coor temp;
		scanf("%d %d %d %d", &temp.x1, &temp.y1, &temp.x2, &temp.y2);
		temp.num = i + 1;
		temp.level = N - i;
		coor.push_back(temp);
		
	//	level[MAX] = i + 1;
	}
	for (i = 0; i < M; i++) {
		Click temp;
		sort(coor.begin(), coor.end());
		scanf("%d %d", &temp.x, &temp.y);
		for (j = 0; j < N; j++  ) {
			if (temp.x >= coor[j].x1&&temp.y >= coor[j].y1&&
				temp.x <= coor[j].x2&&temp.y <= coor[j].y2) {
				//cout << coor[j].num << endl;
				input.push_back(to_string(coor[j].num));
				setLevel(coor, j);
				break;
			}
		}
		if (j >= N) {
			//cout << "IGNORED" << endl;
			input.push_back("IGNORED");
		}
	}

	for (i = 0; i < input.size(); i++)
		cout << input[i] << endl;







	system("pause");
	return 0;
}
