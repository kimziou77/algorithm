#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100'001];

vector<int> answer;
vector<bool> check;

int N;
int bfs(int node) {
	queue<int> q;	q.push(node); check[node] = true;
	int flag = 0;
	int order = 1;
	while (!q.empty()) {
		int tmp = q.front();
		flag = 0;
		for (int i = 0; i < v[tmp].size(); i++) {
			if (!check[v[tmp][i]] && v[tmp][i] == answer[order]) {
				check[v[tmp][i]] = true;
				order++;
				flag = 1;
				q.push(v[tmp][i]);
				break;
			}
		}

		if (!flag) q.pop();
		// 1 플래그가 1인상태로 break; -> 팝하지않고 다시 인접리스트를 돌게된다.
		// 2 for문을 모두 돌아서 끝남; -> 모든 인접리스트를 한번씩 방문했다.

	}

	if (order < N)
		return 0;
	else
		return 1;
}

int main(void) {
	cin >> N;
	answer.resize(N + 1);
	check.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
		cin >> answer[i];

	if (answer[0] != 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	cout << bfs(1);

	return 0;
}
