#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[2'001];
bool check[2'001];
int N, M;

int dfs(vector<int> w, int node) {
	if (w.size() == 5)//끝까지 탐색
		return 1;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!check[next]) {
			check[next] = true;
			w.push_back(next);
			if (dfs(w, next) > 0)
				return 1;
			w.pop_back();
			check[next] = false;
		}
	}
	return 0;
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			if (dfs({ i }, i)) { cout << 1;	return 0; }
			check[i] = false;
		}
	}
	cout << 0;
	return 0;
}