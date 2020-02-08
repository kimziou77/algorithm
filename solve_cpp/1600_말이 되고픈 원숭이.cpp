#include <iostream>
#include <queue>
using namespace std;
struct monkey {
	int h, w;
	int horse;//말처럼 움직인 횟수
};
int K, W, H;
int map[201][201];
int dw[] = { -1,1,0,0  ,2,-2,1,-1,-2,2,-1,1 };
int dh[] = { 0,0,1,-1  ,1,1,2,2,-1,-1,-2,-2 };
bool check[201][201][30];
//0~4 인접칸이동
//5~12 말처럼이동
void bfs(monkey node) {
	int answer = 0;
	queue<monkey> q;	q.push(node);
	check[node.h][node.w][node.horse] = true;

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			monkey tmp = q.front();	q.pop();
			if (tmp.w == W - 1 && tmp.h == H - 1) {
				cout << answer;
				return;
			}
			for (int j = 0; j < 12; j++) {
				monkey ntmp=tmp;
				if (j > 3 && ntmp.horse < K)
					ntmp.horse++;
				else if (j > 3 && ntmp.horse > K - 1)
					break;

				ntmp.w += dw[j];	ntmp.h += dh[j];
				if (ntmp.w<0 || ntmp.h<0 || ntmp.w>W - 1 || ntmp.h>H - 1) continue;

				if (!check[ntmp.h][ntmp.w][ntmp.horse] && map[ntmp.h][ntmp.w] == 0) {
					q.push(ntmp);
					check[ntmp.h][ntmp.w][ntmp.horse] = true;
				}
			}
		}
		answer++;
	}
	cout << -1;
}
int main(void) {
	cin >> K >> W >> H;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];
	bfs({ 0,0,0 });
	return 0;
}