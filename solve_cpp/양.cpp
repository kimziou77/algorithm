#include <iostream>
#include <queue>
#define MAX_SIZE 251
using namespace std;
using pii = pair<int, int>;
int sheep = 0, wolf = 0;
int R, C;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
bool check[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE];
void bfs(int tr,int tc) {//tmp row, tmp col
	//구역마다 bfs가 실행됨
	queue<pii> q;	q.push({ tr,tc });
	int s = 0, w = 0;
	int r, c, nr, nc;
	check[tr][tc] = true;

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			r = q.front().first;	c = q.front().second;	q.pop();
			if (map[r][c] == 'v') w++;
			if (map[r][c] == 'o') s++;

			for (int j = 0; j < 4; j++) {
				nr = r + dr[j];
				nc = c + dc[j];
				if (nr<0 || nc<0 || nr>R - 1 || nc>C - 1) continue;
				if (map[nr][nc]!='#' && !check[nr][nc]) {//벽아니고 간적없으면
					check[nr][nc] = true;
					q.push({ nr,nc });
				}
			}
		}
	}
	if (s > w) sheep += s;
	else wolf += w;
}
int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j]!='#'&&!check[i][j])//벽아니고 간적없으면
				bfs(i,j);

	cout << sheep << " " << wolf;
	return 0;
}