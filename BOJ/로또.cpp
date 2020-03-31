#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int k;
vector<int> v;
vector<int> check;

void dfs(vector<int> lotto,int index){
	if (lotto.size() == 6) {
		for (auto i : lotto)
			printf("%d ", i);
		printf("\n");
		return;
	}

	for (int i = index; i < k; i++) {
		lotto.push_back(v[i]);
		dfs(lotto, i+1);
		lotto.pop_back();
	}
}
int main(void) {

	while (cin >> k && k != 0) {
		vector<int> start;
		v.resize(k);	check.resize(k);
		for (int i = 0; i < k; i++)
			cin >> v[i];
		dfs(start, 0);
		printf("\n");
	}
	return 0;
}