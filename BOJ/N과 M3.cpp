#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int check[10];
vector<int> v;
void NM(int cnt) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		//if (check[i]) continue;
		v.push_back(i);
		//check[i] = true;
		NM(cnt + 1);
		//check[i] = false;
		v.pop_back();
	}
}
int main(void) {
	cin >> N >> M;
	NM(0);
	return 0;
}
