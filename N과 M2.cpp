#include <iostream>
#include <vector>
using namespace std;

int N, M;

int check[10];
vector<int> v;
void NM2(int index,int cnt) {
	if (cnt==M) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = index; i < N; i++) {
		if (check[i])	continue;

		check[i] = true;
		v.push_back(i+1);

		NM2(i, cnt + 1);//index에 대해서 +1 큰 수를 하나씩 넣을 것임..

		v.pop_back();
		check[i] = false;
	}
}
int main(void) {
	cin >> N >> M;
	NM2(0, 0);
	return 0;
}