#include <iostream>
#include <queue>
#define MAX_SIZE 501
using namespace std;
int n, m;
int painting[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int dn[] = { -1,1,0,0 };
int dm[] = { 0,0,1,-1 };
int max_area = 0;

struct pii {
	int n;
	int m;
};
void bfs(pii node) {
	queue<pii> q;
	q.push(node);
	check[node.n][node.m] = true;
	int nn, nm, area = 1;

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pii tmp = q.front();	q.pop();

			for (int j = 0; j < 4; j++) {
				nn = tmp.n + dn[j];
				nm = tmp.m + dm[j];
				if (nn<0 || nm<0 || nn>n - 1 || nm>m - 1) continue;
				if (painting[nn][nm] && !check[nn][nm]) {
					check[nn][nm] = true;
					q.push({ nn,nm });
					area++;
				}
			}
		}
	}
	if (max_area < area) max_area = area;
}
int main(void) {
	int num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> painting[i][j];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			if (painting[i][j]&&!check[i][j]) {
				bfs({ i,j });
				num++;
			}
		}
	}
	cout << num << endl << max_area;
	
	return 0;
}