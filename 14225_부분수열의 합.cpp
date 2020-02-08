#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> S;
bool check[2000021];
void dfs(int index,int sum) {
	if (index == N) return;
	for (int i = index; i < N; i++) {
		sum += S[i];
		if (!check[sum]) {
			check[sum] = true;
		}
		dfs(i + 1, sum);
		sum -= S[i];
	}
}
int sol() {
	int idx=0;
	while (check[++idx]);
	return idx;
}
int main(void) {
	cin >> N;
	S.resize(N);
	for (int i = 0; i < N; i++)
		cin >> S[i];
	dfs(0, 0);
	cout<<sol();
	return 0;
}