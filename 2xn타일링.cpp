#include <iostream>
#include <vector>
using namespace std;
vector<long long> tile;
void dp(int n) {
	tile[1] = 1; tile[2] = 2;
	for (int i = 3; i <= n; i++)
		tile[i] = (tile[i - 1] + tile[i - 2]) %10007;

	cout << tile[n];
}
int main(void) {
	int n;	cin >> n;
	tile.resize(n+1);
	dp(n);
	return 0;
}