#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nj;
vector<int> ok;
bool k=false;
void dfs(int idx, int sel,int sum) {
	if (k) return;
	if (sel == 7 && sum == 100) {
		for (auto i : ok)
			cout << i << endl;
		k = true;
		return;
	}
	for (int i = idx; i < 9; i++) {
		ok.push_back(nj[i]);
		dfs(i + 1, sel + 1, sum + nj[i]);
		ok.pop_back();
	}
}
int main(void) {
	nj.resize(9);
	for (int i = 0; i < 9; i++)
		cin >> nj[i];
	sort(nj.begin(), nj.end());
	cout << endl;
	dfs(0, 0, 0);
	return 0;
}