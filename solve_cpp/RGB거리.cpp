#include <iostream>
#include <algorithm>
using namespace std;
int N;
int cost[3][1001];
void dp() {
	for (int i = 2; i <= N; i++) {
		cost[0][i] = min(cost[1][i - 1], cost[2][i - 1]) + cost[0][i];
		cost[1][i] = min(cost[0][i - 1], cost[2][i - 1]) + cost[1][i];
		cost[2][i] = min(cost[0][i - 1], cost[1][i - 1]) + cost[2][i];
	}
	cout << min(min(cost[0][N], cost[1][N]), cost[2][N]);
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) // 1 ~ N ¹øÂ° Áý
		for (int j = 0; j < 3; j++) // R G B
			cin >> cost[j][i];
	dp();
	return 0;
}

