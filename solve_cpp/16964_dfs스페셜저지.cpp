#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v[100'001];
bool check[100'001];
vector<int> answer;
int order = 1;
int dfs(int node) {

	check[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		if (!check[v[node][i]] && answer[order] == v[node][i]) {
			//이번 depth에서 오더와 같다면
			check[v[node][i]] = true;
			order++;
			dfs(v[node][i]);
			i = -1;
			continue;
		}
	}

	if (order < N) return 0;
	else return 1;
}
int main(void) {
	cin >> N;
	answer.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
		sort(v[i].begin(), v[i].end());

	for (int i = 0; i < N; i++)
		cin >> answer[i];
	cout<<dfs(1);
	return 0;
}