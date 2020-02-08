#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int N, M;
int map[1001][1001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<pii> wall;

int bfs(int index, int map[][1001]);
void move() {
	//wall의 인덱스 i번째 부터 하나씩 부수고, bfs진행
	for (int i = 0; i < wall.size(); i++) {
		int tmp = bfs(i, map);//부수고
		map[wall[i].first][wall[i].second] = tmp%10;//갱신
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
}
int bfs(int index,int map[][1001]) {

	int w_x = wall[index].first;
	int w_y = wall[index].second;
	int dist = 1;

	int x,y,nx, ny;
	vector<vector<bool>> check(N,vector<bool>(M,false));

	queue<pii> q;	q.push({ w_x,w_y }); check[w_x][w_y] = true;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			x = q.front().first;	y = q.front().second;	q.pop();

			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];	ny = y + dy[i];
				if (nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;

				if (map[nx][ny] == 0 && !check[nx][ny]) {
					check[nx][ny] = true;	q.push({ nx,ny });
					dist++;
				}
			}
		}
	}
	return dist;
}
int main(void) {
	cin >> N >> M;//M : 세로  N : 가로

	for (int i = 0; i < N ; i++)
		for (int j = 0; j < M ; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1)
				wall.push_back({ i,j });
		}

	move();

	return 0;
}