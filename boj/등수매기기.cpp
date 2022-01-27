#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int n;	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	long long sum = 0;
	for (int i = 1; i < n + 1; i++)
		sum += abs(i - v[i-1]);
	cout << sum;

	return 0;
}