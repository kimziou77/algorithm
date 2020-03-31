#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#define MAX_SIZE 11

using namespace std;
int N;
int map[MAX_SIZE][MAX_SIZE];
int cost = INT_MAX;
struct pii {
	int r, c;
};
vector<pii> v;
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,1,-1 };
int flower(vector<pii> v) {
	bool check[MAX_SIZE][MAX_SIZE];
	memset(check, false, sizeof(check));
	int nr, nc, sum = 0;
	for (auto f : v) {//3
		check[f.r][f.c] = true;
		sum += map[f.r][f.c];
		for (int i = 0; i < 4; i++) {//4
			nr = f.r + dr[i];	nc = f.c + dc[i];
			//if flower is over map, return INT_MAX
			if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) return INT_MAX;
			//if flower is already bloom, return INT_MAX
			if (check[nr][nc]) return INT_MAX;
			check[nr][nc] = true;
			sum += map[nr][nc];
		}
	}
	return sum;
}
void dfs(int num) {
	if (v.size() == 3) {
		int tmp = flower(v);
		if (tmp < cost)	cost = tmp;
		//for (auto i : v) {
		//	cout << i.r << " " << i.c << " // ";
		//}
		//cout << "------------------------\n";
		return;
	}
	for (int i = num + 1; i < N * N; i++) {
		v.push_back({ i / N,i % N });
		dfs(i);
		v.pop_back();
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	dfs(0);
	cout << cost;
	return 0;
}
