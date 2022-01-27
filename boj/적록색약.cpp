#include <iostream>
#include <cstdio>
#include <queue>
#pragma warning(disable:4996)
#define MAX_SIZE 101
using namespace std;
int N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

char grim[MAX_SIZE][MAX_SIZE];
int check[MAX_SIZE][MAX_SIZE];

using pii = pair<int, int>;
void bfs(pii node) {
	int nx, ny, x, y;
	char rgb = grim[node.first][node.second];
	if (grim[node.first][node.second] == 'R') grim[node.first][node.second] = 'G';
	queue<pii> q;
	q.push({ node.first, node.second });
	check[node.first][node.second] = true;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			x = q.front().first; y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				nx = x + dx[j]; ny = y + dy[j];
				if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
				if (!check[nx][ny] && grim[nx][ny]==rgb) {

					if (grim[nx][ny] == 'R')	grim[nx][ny] = 'G';

					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf(" %1c", &grim[i][j]);
	int yes = 0; // ���ϻ����� ��� ��
	int no = 0;  // ���ϻ����� �ƴ� ��� ��

	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++){
			if (!check[i][j]) {
				bfs({ i,j });
				no++;
			}
		}
	}


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				bfs({ i,j });
				yes++;
			}
		}
	}
	cout << no << " " << yes;

	return 0;
}