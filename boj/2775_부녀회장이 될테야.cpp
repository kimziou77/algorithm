#include <iostream>
#define MX 15
using namespace std;

int main(void) {
	int T;	cin >> T;
	while (T--) {
		int K, N;	cin >> K >> N;//k���� nȣ�� ����� ��� �ִ°�?
		int people[MX][MX];

		for (int i = 1; i < MX; i++)
			people[0][i] = i;

		for (int i = 1; i < MX ; i++) {//����
			for (int j = 1; j < MX ; j++) {//ȣ��
				int sum = 0;
				for (int k = 1; k <= j; k++) {
					sum += people[i-1][k];
				}
				people[i][j] = sum;
				if (i == K && j == N) {
					cout << people[i][j] << "\n";
					i = MX; break;
				}
				
			}
		}
	}
	return 0;
}