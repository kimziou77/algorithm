#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N, M;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<int, bool> num;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;	cin >> a;
		num[a] = true;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		cout << num[a]<<"\n";
	}
	return 0;
}