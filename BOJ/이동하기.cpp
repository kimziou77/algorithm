#include <iostream>
#define MAX_SIZE 1001
using namespace std;
int n, m;
int map[MAX_SIZE][MAX_SIZE];
int candy[MAX_SIZE][MAX_SIZE];
int max(int a, int b) {
	return (a > b) ? a : b;
}
int MAX(int a, int b, int c) {
	int m=max(a, b);
	return max(m, c);
}
void dp(void) {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			candy[i][j] = MAX(	candy[i - 1][j] + map[i][j],
								candy[i][j - 1] + map[i][j],
								candy[i - 1][j - 1] + map[i][j]);
		}
	}
	cout << candy[n][m];
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < m+1; j++)
			cin >> map[i][j];
	dp();

	return 0;
}