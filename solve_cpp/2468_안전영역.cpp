#include <iostream>
#include <vector>
#include <queue>
#define MX 101
using namespace std;
struct pii {
	int r, c;
};
struct rain {
	int h;//실제 높이랑
	int water = 0;//현재까지 쌓인 물의 높이
};
rain map[MX][MX];
int N;
int mx_num;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(pii node,int height) {
	queue<pii> q;
	int nr, nc;
	q.push(node);
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pii tmp = q.front(); q.pop();
			for (int j = 0; j < 4; j++) {
				nr = tmp.r + dr[j];
				nc = tmp.c + dc[j];

				//맵을 벗어나면 안됨
				if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) continue;

				//갈 수 없거나, 이미 물로 잠긴 지역이면 갈 필요 없음.
				if (map[nr][nc].h == 0 || map[nr][nc].water >= height) continue;
				else {
					map[nr][nc].water = height;
					q.push({ nr,nc });
				}
			}
		}
	}
}

int main(void) {
	int max_safe = 0;
	cin >> N;
	vector<pii> v[101]; // v[i] : i의 높이를 가진 좌표들을 저장한 백터
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j].h;
			v[map[i][j].h].push_back({ i,j });
			if (mx_num < map[i][j].h) mx_num = map[i][j].h;
		}
	}
		
	for (int i = 0; i <= mx_num; i++) {//장마가 와서 물이 점점 차오름
		int safe = 0;
		if (i == 0) safe = 1;
		for (pii h : v[i]) { //물에 잠기는 지역
			map[h.r][h.c].h = 0;
			map[h.r][h.c].water = i;
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				//물에 잠기지 않았거나, (물에 잠기지 않았고 이미 물이 차오르지 않음=방문안함)
				if (map[j][k].h!=0 && map[j][k].water < i) {
					bfs({ j,k }, i);//물에 잠기지 않았다면 bfs!
					safe++;
				}
			}
		}
		if (max_safe < safe) max_safe = safe;
	}
	cout << max_safe;

	return 0;
}