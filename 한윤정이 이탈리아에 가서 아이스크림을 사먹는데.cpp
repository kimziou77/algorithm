#include <iostream>
using namespace std;
int N, M;

//0번째 아이스크림 x
bool DONT[10002][10002];//같이 먹으면안되는 조합


bool check(int i,int j ,int k) {
	return DONT[i][j] || DONT[i][k] || DONT[j][k];
}
int main(void) {
	int count = 0;
	cin >> N >> M;
	//아이스크림 3개선택

	//섞어먹으면 안되는 조합의 번호
	for (int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		DONT[a][b] = true;
		DONT[b][a] = true;
	}

	for (int i = 1; i <= N; i++)
		for (int j = i+1; j <= N; j++)
			for (int k = j+1; k <= N; k++)
				if (!check(i, j, k))
					count++;

	cout << count;
	return 0;
}