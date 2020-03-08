#include <iostream>
#include <vector>
#define MX 500'001
using namespace std;

vector<int> v[MX];
bool check[MX];
int sum = 0;
void dfs(int depth, int idx) {
	int child_num = 0;
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (!check[next]) {
			check[next] = true;
			dfs(depth + 1, next);
			child_num++;
		}
	}
	if (child_num == 0) sum += depth;
}
int main(void) {
	int N; cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	check[1] = true;
	dfs(0, 1);

	if (sum&1) cout << "Yes";
	else cout << "No";
	return 0;
}