#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;
struct SCV {
	int x = 0, y = 0, z = 0;
	int die = 0;
};
bool check[61][61][61][4];
int N;
vector<vector<int>> p;
int bfs(SCV node) {
	int a = node.x, b = node.y, c = node.z, d = node.die;
	queue<SCV> q;	q.push({ a,b,c,d });	check[a][b][c][d] = true;
	int na = a, nb = b, nc = c, atk = 0;

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			SCV scv = q.front(); q.pop();
			a = scv.x;	b = scv.y;	c = scv.z;

			if (scv.die == 3) { return atk; }

			for (auto pain : p) {//순열 하나
				d = 0;
				na = a - pain[0];
				nb = b - pain[1];
				nc = c - pain[2];
				if (na <= 0) { na = 0; d++; }
				if (nb <= 0) { nb = 0; d++; }
				if (nc <= 0) { nc = 0; d++; }
				if (!check[na][nb][nc][d]) {
					check[na][nb][nc][d] = true;
					q.push({ na,nb,nc,d });
				}
			}
		}
		atk++;
	}
}
int attack = 0;


int main(void) {
	vector<int> hp(3, 0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> hp[i];

	vector<int> v = { 1,3,9 };
	do {
		p.push_back(v);
	} while (next_permutation(v.begin(), v.end()));

	cout << bfs({ hp[0], hp[1], hp[2] ,0 });
	return 0;
}