#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int check[10];
vector<int> v;
vector<int> arr;
void NM(int index, int cnt) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		v.push_back(arr[i]);
		check[i] = true;
		NM(i, cnt + 1);
		check[i] = false;
		v.pop_back();
	}
}
int main(void) {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	cout << 1 << " " << arr.size()<<endl;
	arr.erase(unique(arr.begin(), arr.end()),arr.end());
	cout << 2 << " " << arr.size()<<endl;

	NM(0, 0);
	return 0;
}
