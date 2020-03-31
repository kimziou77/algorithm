#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
bool map[101][101];
void square(int x1, int y1, int x2, int y2) {
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			map[j][i] = true;
}
int area = 0;
void dfs(int r, int c) {
	area++;
	map[r][c] = true;
	int nr, nc;
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 0 || nc<0 || nr>M - 1 || nc>N - 1) continue;
		if (!map[nr][nc])	dfs(nr, nc);
	}
}

int main(void) {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		square(a, b, c, d);
	}
	vector<int> answer;
	int ans=0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) {
				area = 0;
				ans++;
				dfs(i, j); //y,x
				answer.push_back(area);
			}
		}
	}
	cout << ans << "\n";
	sort(answer.begin(), answer.end());
	for (auto i : answer)
		cout << i << " ";
	return 0;
}
/*
void print_map() {
	cout << "-----------------------------\n";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------\n";

}
*/