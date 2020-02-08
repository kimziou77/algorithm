#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> A;
int N, L, R, X;
ll hard, easy,num=0;

void dfs(int index,ll hard, ll easy,ll sum,int sel) {
	if (sum > R) return;

	if (sum >= L && sum <= R && hard - easy >= X && sel>=2 ) {
		num++;
	}

	for (int i = index; i < N; i++) {
		int nhard = hard,neasy=easy;
		if (A[i] > hard) nhard = A[i];
		if (A[i] < easy) neasy = A[i];
		dfs(i + 1, nhard, neasy, sum+A[i] ,sel+1);
	}
}
int main(void) {
	cin >> N >> L >> R >> X;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	dfs(0,INT_MIN,INT_MAX,0,0);

	cout << num;
	return 0;
}
