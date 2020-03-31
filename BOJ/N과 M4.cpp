#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int check[10];
vector<int> v;
void NM(int index,int cnt) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i = index; i < N; i++) {
		//if (check[i]) continue;
		v.push_back(i+1);
		//check[i] = true;
		NM(i,cnt + 1);
		//check[i] = false;
		v.pop_back();
	}
}
int main(void) {
	cin >> N >> M;
	NM(0,0);
	return 0;
}
