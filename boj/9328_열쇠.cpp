#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX_SIZE 103
using namespace std;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,1,-1 };

int h, w;
int paper = 0;

vector<vector<char>> map(MAX_SIZE, vector<char>(MAX_SIZE, '.'));
vector<bool> key(26, false);

struct pii {
	int r, c;
};
int kind(char m) {
	if (m >= 'A' && m <= 'Z') return 0;
	if (m >= 'a' && m <= 'z') return 1;
	if (m == '.') return 2;
	if (m == '$') return 3;
	if (m == '*') return 4;
}
void print_map(int nr,int nc) {
	for (int i = 0; i < 26; i++) {
		cout << key[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < w + 2; j++) {
			if (i == nr && j == nc) {
				cout << "@";
			}
			else
				cout << map[i][j];
		}
		cout << endl;
	}
	cout << "---------------------------------------------------\n\n";
}
void bfs(pii SG) {
	int nr, nc;
	vector<vector<bool>> check(h + 2, vector<bool>(w + 2, false));

	queue<pii> door[26];//문 위치 저장 큐
	queue<pii> q;	q.push(SG);//상근이 탐색위치 저장 큐

	check[SG.r][SG.c] = true;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pii tmp = q.front();	q.pop();

			for (int j = 0; j < 4; j++) {
				int nr = tmp.r + dr[j];
				int nc = tmp.c + dc[j];
				if (nr<0 || nc<0 || nr>h + 1 || nc>w + 1) continue;
				char& next = map[nr][nc];

				if (!check[nr][nc] && next != '*') {//벽이 아니고 탐색안했으면
					check[nr][nc] = true;

					enum { DOOR, KEY, EMPTY, FIND, WALL };
					//print_map(nr,nc);
					switch (kind(next)) {
					case DOOR: {
						if (key[next - 'A'])//열쇠가 있으면
							q.push({ nr,nc });//계속탐색
						else
							door[next - 'A'].push({ nr,nc });
						break;
					}
					case KEY: {
						key[next - 'a'] = true;//열쇠 줍고

						//아까 열지못한 문의 위치값을 저장한 queue
						auto & d = door[next - 'a'];
						while (!d.empty()) {
							q.push(d.front());
							d.pop();
						}
						q.push({ nr,nc });
						next = '.';
						break;
					}
					case EMPTY:
						q.push({ nr,nc });
						break;
					case FIND:
						paper++;
						q.push({ nr,nc });
						next = '.';
					case WALL:
						break;
					}
				}
			}
		}
	}
}
void reset() {
	paper = 0;
	key.assign(26, false);
	map.assign(MAX_SIZE, vector<char>(MAX_SIZE, '.'));
}
int main(void) {
	int T;	cin >> T;
	while (T--) {
		cin >> h >> w;//2~100

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> map[i][j];

		string k;	cin >> k;
		for (int i = 0; i < k.size(); i++) {
			int ky = k[i] - 'a';
			if (ky >= 0) key[ky] = true;
		}
		bfs({ 0,0 });
		//while (bfs({ 0,0 }));
		//for (int i = 0; i <= h+1; i++)
		//	for (int j = 0; j <= w+1; j++)
		//		if (!check_area[i][j]) {
		//			while (bfs({ 0,0 }));//bfs start
		//		}

		cout << paper << "\n";
		reset();

	}

	return 0;
}
