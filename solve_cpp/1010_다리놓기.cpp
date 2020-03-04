#include <iostream>
#include <vector>
using namespace std;
int d[31][31];
void dp() {
	d[1][0] = 1; d[1][1] = 1;
	for (int i = 2; i < 31; i++) {
		d[i][0] = 1; d[i][i] = 1;
		for (int j = 1; j < i; j++) {
			d[i][j] = d[i - 1][j-1] + d[i - 1][j];
		}
	}
}
int main(void) {
	int T;	cin >> T;
	dp();
	while (T--) {
		int n, m;	cin >> n >> m;
		cout<<d[m][n]<<endl;
	}

	return 0;
}
/*
int foo(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (d[n][r]) return d[n][r];
	return d[n][r] = foo(n - 1, r - 1) + foo(n - 1, r);
}
*/