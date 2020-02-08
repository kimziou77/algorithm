#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int map[1001][1001];
int n, m;
int max_size = 0;
int sol() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]!=0) {
				int& L = map[i][j - 1];	
				int& U = map[i - 1][j];
				int& LU = map[i - 1][j - 1];
				// if(L==U && U ==LU) ,,,map +1

				map[i][j] = min(min(L, U), LU)+1;

				if (map[i][j] > max_size)	max_size = map[i][j];
			}
		}
	}
	return max_size * max_size;
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	cout << sol();
	return 0;
}