#include <iostream>
#include <cstdio>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
using namespace std;
using pii = pair<int, int>;

//1 시계 -1 반시계
int gear[4][8];

void clock(int g) {
	int tmp = gear[g][7];
	for (int i = 6; i >= 0; i--) {
		gear[g][i + 1] = gear[g][i];
	}
	gear[g][0] = tmp;
}
void unClock(int g) {
	int tmp = gear[g][0];
	for (int i = 1; i < 8; i++) {
		gear[g][i - 1] = gear[g][i];
	}
	gear[g][7] = tmp;
}
void rotate(int g, int r) {
	if (r == 1)
		clock(g);
	else
		unClock(g);
}
vector<bool> check(int g ) {
	vector<bool> check(4, false);
	check[g] = true;

	for (int i = g ; i<3&& gear[i][2] != gear[i + 1][6]; i++){
		if(i<3)
			check[i + 1] = true;
	}

	for (int i = g;i>0&& gear[i-1][2] != gear[i][6] ;i--) {
		if(i>0)
			check[i - 1] = true;
	}
	return check;
}
void run(int n, int r) {//n번기어를 r방향회전
	vector<bool> check_gear = check(n);
	for (int i = 0; i < 4; i++) {
		if (check_gear[i]) {
			if ((n - i) & 1)
				rotate(i, r * (-1));
			else
				rotate(i, r);
		}
	}
}
int main(void) {
	int sum = 0;
	int k;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);

	cin >> k;
	for (int i = 0; i < k; i++){
		int n, r;	cin >> n >> r;
		run(n-1, r);
	}

	//점수계산
	for (int i = 0; i < 4; i++)
		if(gear[i][0]==1)
			sum += (1 << i);
	cout << sum;
	return 0;
}