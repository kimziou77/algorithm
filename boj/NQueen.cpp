#include <iostream>
#include <algorithm>
using namespace std;
int N,num;
int col[15];
bool promising(int m) {//m���� �� �˻�
	for (int i = 1; i < m; i++) {
		if (col[m] == col[i] || abs(col[m] - col[i]) == abs(m - i)) return false;
		//�������� �ִ���, �밢���� �ִ���!
	}
	return true;
}
void nQueen(int n) {//n���� ��ġ�ϴ� �Լ�
	if (n == N) {
		num++;
		return;
	}
	for (int i = 1; i <= N; i++) {//ù°�ٺ��� N��°�ٱ��� �˻�.
		col[n+1] = i;//n��° ���� i���� �־��.
		if (promising(n+1))//�����ϸ�
			nQueen(n + 1);//�������� ��ġ�Ѵ�.
	}
}

int main(void) {
	cin >> N;
	nQueen(0);
	cout << num;
	return 0;
}