#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Input();

int N, K;//N : 손동작수, K : 우승을 위해 필요한 승수
int A[10][10];//i에 대한 j의 상성이 k이다.
int win[3],order[3];
vector<int> sheet[3];


enum { Z, G, M };//지우, 경희, 민호
bool inside(int front, int back) {//라운드는 알아서 20번 이내로 끝남.

	if (win[Z] == K) return true;
	if (win[G] == K || win[M] == K) {
		return false;
	}

	int next = 3 - front - back;
	int tmpWin=2;

	int i = sheet[front][order[front]];
	int j = sheet[back][order[back]];
	if (i == 0 || j == 0) return false;

	order[front]++;	order[back]++;//냈으니까 ++

	enum { LOSE, DRAW, WIN };
	switch (A[i][j]) {
	case WIN:
		win[front]++;
		return inside(front,next);
	case DRAW:
		tmpWin = (front > back) ? front : back;
		win[tmpWin]++;
		return inside(tmpWin, next);
	case LOSE:
		win[back]++;
		return inside(back, next);
	}
}

int main(void) {
	cin >> N >> K;
	Input();

	do {
		if (inside(Z, G)) {
			cout << 1;
			return 0;
		}
		for (int i = 0; i < 3; i++) {
			win[i] = 0;	order[i] = 0;
		}
	} while (next_permutation(&sheet[0][0],&sheet[0][N]));

	cout << 0;
	return 0;
}

void Input() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			A[j][i] = abs(A[i][j] - 2);
		}
	}

	for (int i = 0; i < 3; i++)
		sheet[i].resize(20);
	for (int i = 1; i <= N; i++)
		sheet[0][i - 1] = i;
	for (int i = 0; i < 20; i++)
		cin >> sheet[1][i];
	for (int i = 0; i < 20; i++)
		cin >> sheet[2][i];
}
