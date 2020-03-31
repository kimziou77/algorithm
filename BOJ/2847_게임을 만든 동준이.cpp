#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int sum = 0;
	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i] <= v[i - 1]) {
			sum += v[i-1]-(v[i]- 1);
			v[i - 1] = v[i] - 1;
		}
	}
	cout << sum;
	return 0;
}