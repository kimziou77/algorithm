#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
#include <random>
#define S 0 //���
#define G 1 //�ٻ�
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
	
	int now = card[turn].front(); //�ڽ��� ������ �ִ� ���� ���� ���� ���ӽ���
	card[turn].pop_front();

	if (card[turn].size() == 0) {//ī�带 ��� ����ϸ� ��������
		score[turn] += card[!turn].size();//�������� �����ִ� ī�� ���� ����
		return;
	}

	do {
		//�����ִ� ������ ū ���� ���� ������ ã��
		auto next = upper_bound(card[!turn].begin(), card[!turn].end(), now);

		if (next == card[!turn].end()) {
			return game(turn);//��밡 ��ī�尡 ���ٸ� �� ���ʷ� �ٽ� ���ӽ���.
		}
		else {
			now = *next;
			card[!turn].erase(next);//ī�� ����

			if (card[!turn].size() == 0) return game(!turn);
			turn = !turn;//���� ����
		}
	} while (1);

}
int main(void) {
	Input();
	game(S);//����̷� ���ӽ���!
	cout << score[S] << endl << score[G];
	return 0;
}