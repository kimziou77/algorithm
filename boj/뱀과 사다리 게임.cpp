#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int N, M;
bool check[101];
map<int, int> ladder;//��ٸ�
map<int, int> snake;//��
int play(int node) {
	queue<int> q;	q.push(node);	check[node] = true;
	int now,tmp;
	int answer = 0;
	while (!q.empty()) {
		int sz = q.size();

		for (int i = 0; i < sz; i++) {
			now = q.front();	q.pop();
			if (now == 100) {
				while (!q.empty())	q.pop();
				return answer;
			}
			for (int j = 1; j <= 6; j++) {
				tmp = now + j;
				if (!check[tmp]) {

					if (ladder[tmp]!=0)//��ٸ����ִٸ�
						tmp = ladder[tmp];//��ٸ���
					if (snake[tmp]!=0)//�����ִٸ�
						tmp = snake[tmp];//������

					q.push(tmp);
					check[tmp] = true;
				}
			}
		}
		answer++;

	}


}
int main(void) {
	cin >> N >> M;
	int x, y, u, v;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		ladder.insert({ x,y });
	}

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		snake.insert({ u,v });
	}

	cout << play(1);//1��° ĭ���� ����

	return 0;
}