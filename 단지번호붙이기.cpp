#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX_SIZE 26
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
using pii = pair<int, int>;

int map[MAX_SIZE][MAX_SIZE];
int n;
vector<int> danji;
void bfs(pii node) {
	queue<pii> q; 
	int nx, ny, x, y;

	map[node.first][node.second] = 0;
	q.push({ node.first,node.second });
	int num = 1;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				nx = x + dx[j]; ny = y + dy[j];

				if (nx<0 || ny<0 || nx>n-1 || ny>n-1) continue;//범위 밖이면 continue

				if (map[nx][ny]) {//방문 안했으면 넣고 돌린다
					map[nx][ny] = 0;//방문한 상태로 바꿔준다.
					q.push({ nx,ny });
					num++;
				}
			}


		}
	}
	danji.push_back(num);
}





int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				bfs({ i,j });
				answer++;
			}
		}
	}
	sort(danji.begin(), danji.end());
	cout << answer<<endl;
	for (auto i : danji)
		cout << i << endl;
	
	return 0;
}