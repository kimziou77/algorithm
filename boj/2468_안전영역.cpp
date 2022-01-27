#include <iostream>
#include <vector>
#include <queue>
#define MX 101
using namespace std;
struct pii {
	int r, c;
};
struct rain {
	int h;//���� ���̶�
	int water = 0;//������� ���� ���� ����
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

				//���� ����� �ȵ�
				if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) continue;

				//�� �� ���ų�, �̹� ���� ��� �����̸� �� �ʿ� ����.
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
	vector<pii> v[101]; // v[i] : i�� ���̸� ���� ��ǥ���� ������ ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j].h;
			v[map[i][j].h].push_back({ i,j });
			if (mx_num < map[i][j].h) mx_num = map[i][j].h;
		}
	}
		
	for (int i = 0; i <= mx_num; i++) {//�帶�� �ͼ� ���� ���� ������
		int safe = 0;
		if (i == 0) safe = 1;
		for (pii h : v[i]) { //���� ���� ����
			map[h.r][h.c].h = 0;
			map[h.r][h.c].water = i;
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				//���� ����� �ʾҰų�, (���� ����� �ʾҰ� �̹� ���� �������� ����=�湮����)
				if (map[j][k].h!=0 && map[j][k].water < i) {
					bfs({ j,k }, i);//���� ����� �ʾҴٸ� bfs!
					safe++;
				}
			}
		}
		if (max_safe < safe) max_safe = safe;
	}
	cout << max_safe;

	return 0;
}