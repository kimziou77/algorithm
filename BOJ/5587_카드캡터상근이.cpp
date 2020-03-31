#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
#include <random>
#define S 0 //상근
#define G 1 //근상
using namespace std;
deque<int> card[2];
int score[2];
int n;
void Input() {
	cin >> n;
	card[S].resize(n);
	for (int i = 0; i < n; i++)
		cin >> card[S][i];

	sort(card[S].begin(), card[S].end());

	for (int i = 1, order = 0; i <= 2 * n; i++) {
		if (order < n && card[S][order] == i) order++;
		else card[G].push_back(i);
	}
}
void game(int turn) {
	
	int now = card[turn].front(); //자신이 가지고 있는 가장 작은 수로 게임시작
	card[turn].pop_front();

	if (card[turn].size() == 0) {//카드를 모두 사용하면 게임종료
		score[turn] += card[!turn].size();//상대방한테 남아있는 카드 수가 점수
		return;
	}

	do {
		//나와있는 수보다 큰 수를 상대방 덱에서 찾기
		auto next = upper_bound(card[!turn].begin(), card[!turn].end(), now);

		if (next == card[!turn].end()) {
			return game(turn);//상대가 낼카드가 없다면 내 차례로 다시 게임시작.
		}
		else {
			now = *next;
			card[!turn].erase(next);//카드 제출

			if (card[!turn].size() == 0) return game(!turn);
			turn = !turn;//순서 변경
		}
	} while (1);

}
int main(void) {
	Input();
	game(S);//상근이로 게임시작!
	cout << score[S] << endl << score[G];
	return 0;
}