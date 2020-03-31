#include <iostream>
using namespace std;
int num;
bool paper[101][101];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
void squre(int c, int r) {
	paper[r][c]=true;
	int nr, nc;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			nr = r + i;	nc = c + j;
			paper[nr][nc] = true;
		}
	}
}
int area = 0;
void dfs(int r, int c) {
	paper[r][c] = false;
	area++;
	int nr, nc;
	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr>=100 || nc>=100) continue;
		if(paper[nr][nc])	dfs(nr, nc);
	}
}
void print_map() {
	cout << "---------------------------------------\n";
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << paper[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "---------------------------------------\n";
}
int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a, b; cin >> a >> b;
		squre(a, b);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) {
				dfs(i, j);
			}
		}
	}
	cout << area;
	return 0;
}