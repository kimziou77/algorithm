#include <iostream>
#include <algorithm>
using namespace std;
int N,num;
int col[15];
bool promising(int m) {//m번쨰 행 검사
	for (int i = 1; i < m; i++) {
		if (col[m] == col[i] || abs(col[m] - col[i]) == abs(m - i)) return false;
		//같은열에 있는지, 대각선에 있는지!
	}
	return true;
}
void nQueen(int n) {//n퀸을 배치하는 함수
	if (n == N) {
		num++;
		return;
	}
	for (int i = 1; i <= N; i++) {//첫째줄부터 N번째줄까지 검사.
		col[n+1] = i;//n번째 퀸을 i열에 넣어본다.
		if (promising(n+1))//가능하면
			nQueen(n + 1);//다음퀸을 배치한다.
	}
}

int main(void) {
	cin >> N;
	nQueen(0);
	cout << num;
	return 0;
}