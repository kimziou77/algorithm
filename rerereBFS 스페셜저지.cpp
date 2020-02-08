#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100'001];
bool check[100'001];
int answer[100'001];
int N;
int bfs() {
	queue<int> q; q.push(1); check[1] = true;
	int order = 1,flag;
	while (!q.empty()) {
		int node = q.front();
		flag = 0;
		for (int i = 0; i <v[node].size() ; i++) {
			int next = v[node][i];
			if (!check[next]&&next==answer[order]) {
				check[next] = true;
				order++;
				flag = 1;
				break;
			}
			if (!flag) q.pop();
		}
	}
	if (order < N) return -1;

	return 0;
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> answer[i];
	}
	cout << bfs();
	return 0;
}