#include <iostream>
#include <vector>
using namespace std;
int dr[] = {0,1,0,-1};
int dc[] = {-1,0,1,0};
int main(void) {
	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> v(n,vector<int>(n,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	vector<vector<int>> copy(v);
	vector<vector<bool>> check(n, vector<bool>(n, false));
	while (r--) {
		for (int i = 0; i < n; i++) {
			int dir = 0;
			for (int j = 0; j < n; j++) {
				int nr = i + dr[dir];
				int nc = j + dc[dir];
				if (nr < 0 || (dir == 3 && check[nr][nc])) {
					dir = 0; j--; continue;
				}
				if (nc < 0 || (dir == 0 && check[nr][nc])) {
					dir = 1; j--; continue;
				}
				if (nr > n - 1 || (dir == 1 && check[nr][nc])) {
					dir = 2; j--; continue;
				}
				if (nc > n - 1 || (dir == 2 && check[nr][nc])) {
					dir = 3; j--; continue;
				}
				copy[nr][nc] = v[i][j];
				check[nr][nc] = true;
				for (auto i : copy) {
					for (auto j : i)
						cout << j << " ";
					cout << endl;
				}
				cout << "-------------------------" << endl;
			}
		}
	}
	for (auto i : copy) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
