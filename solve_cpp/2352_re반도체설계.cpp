#include <iostream>
#include <climits>
#include <queue>
using namespace std;
deque<int> LIS;
int n;
vector<int> v;
int main(void) {
	cin >> n;
	v.resize(n);
	LIS.push_back(INT_MIN);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++) {
		int back = LIS.back();
		if (back < v[i])
			LIS.push_back(v[i]);
		else {
			auto locate = lower_bound(LIS.begin(), LIS.end(), v[i]);
			*locate = v[i];
		}
	}
	cout << LIS.size()-1;
	return 0;
}