#include <iostream>
#include <vector>
using namespace std;

int N, M;
int main(void) {
	cin >> N >> M;
	vector<int> student(N + 1);
	vector<bool> check(N + 1,false);
	for (int i = 1; i <= N; i++)
		student[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		student[a]++; student[b]--;
	}
	for (int i = 1; i <= N; i++) {
		if (student[i]<0 || student[i]>N||check[student[i]]) {
			cout << -1;
			return 0;
		}
		check[student[i]] = true;
	}

	for (int i = 1; i <= N; i++)
		cout << student[i] << " ";

	return 0;
}
/*
각 학생은 1부터 N까지
서로 다른 번호가 적힌 카드들 중 하나를 가지고 있다
뒤에 서있으면서 더 작은 번호의 카드를 가진 학생들의 명단을 하나도 빠짐없이 모두 받았다

*/