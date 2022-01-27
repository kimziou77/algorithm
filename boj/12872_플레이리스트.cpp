#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n, l, r, x;
int answer = 0;
deque<int> selected;
deque<int> problem;

bool check() {
	int sum = 0;
	for (auto n : selected)
		sum += n;

	if (sum >= l && sum <= r && selected.back() - selected.front() >= x)
		return true;
	else
		return false;
}

int dfs(int depth, int index, int cnt) {
	if (depth == cnt) {
		if (check())
			answer++;
	}

	for (int i = index; i < n; i++) {
		selected.push_back(problem[i]);
		dfs(depth + 1, i + 1, cnt);
		selected.pop_back();
	}

}

int main(void) {
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) {
		int n1;
		cin >> n1;
		problem.push_back(n1);
	}
	sort(problem.begin(), problem.end());
	for (int i = 2; i <= n; i++)
		dfs(0, 0, i);

	cout << answer << endl;
	return 0;
}