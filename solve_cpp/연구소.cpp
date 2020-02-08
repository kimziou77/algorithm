#include <iostream>
#include <vector>
#include <queue>
#define NEW_WALL 9
using namespace std;
int N, M;
using pii = pair<int, int>;

int map[8][8];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0, 1,-1 };
vector<pii> virus;
int wall_count = 3;

int __virus(int x, int y) {
	int vr = 0;
	if (map[x][y] == 2)
		vr--;
	else
		map[x][y] = 3;

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < N && ty < M && map[tx][ty] == 0)
			vr += __virus(tx, ty);
	}
	return vr + 1;
}
int make_wall(int index, int cnt) {
	int answer = 999999;

	if (cnt == 3) {
		int vr = 0;
		for (auto v : virus)
			vr += __virus(v.first, v.second);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 3)
					map[i][j] = 0;

		return vr;
	}
	while (index < N * M) {
		int i = index / M, j = index % M;
		if (map[i][j] == 0) {
			map[i][j] = NEW_WALL;
			answer = min(answer, make_wall(index + 1, cnt + 1));
			map[i][j] = 0;
		}
		index++;
	}

	return answer;
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });
			else if (map[i][j] == 1) {
				wall_count++;
			}
		}

	cout << N * M - wall_count - virus.size() - make_wall(0, 0) << endl;
	return 0;
}