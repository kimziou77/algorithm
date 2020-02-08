#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> arr(n);
		int even = 0, odd = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] & 1)
				odd++;
			else
				even++;
		}
		if (odd & 1)
			cout << "YES\n";
		else if (odd == 0)
			cout << "NO\n";
		else if (odd!=0 && !(odd%2) && even > 0)
			cout << "YES\n";
		else if(!(odd&1) &&even<=0)
			cout << "NO\n";
	}
	return 0;
}