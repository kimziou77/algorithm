#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> computer[101];
bool check[101];
int bfs(int start) {
	int size = 0;
	queue<int> q;	check[start] = true;	 q.push(start);
	while (!q.empty()) {
		int node = q.front(); q.pop();
		int sz= computer[node].size();
		for (int i = 0; i < computer[node].size(); i++) {
			int next = computer[node][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
				size++;
			}
		}
	}
	return size;
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;	cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	cout<<bfs(1);

	return 0;
}