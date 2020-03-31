#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[100001];
int n, k;
void bfs(int node) {
	if (node == k) {
		cout << 0;
		return;
	}

	queue<int> q;
	q.push(node); check[node] = true;
	int time = 0;//수빈이가 동생을 찾는 가장 빠른시간
	
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int x = q.front();	q.pop();
			vector<int> move;
			move.push_back(-1); move.push_back(1); move.push_back(x);

			for (int j = 0; j < 3; j++) {
				int nx = x + move[j];
				if (nx == k) {
					cout << time + 1;
					return;
				}
				if (nx < 0 || nx>100000) continue;
				if (!check[nx]) {//아직 가지 않았다면
					check[nx] = true;
					q.push(nx);
				}
			}
		}
		time++;
	}

}
int main(void) {
	cin >> n >> k;
	bfs(n);
	return 0;
}