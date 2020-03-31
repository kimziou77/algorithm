#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		multiset<int> A;
		multiset<int> B;
		int Anum[5],Bnum[5];

		int as;	cin >> as;//1
		for (int j = 0; j < as; j++) {
			int a;	cin >> a;
			A.insert(a);
		}

		int bs;	cin >> bs;//4
		for (int j = 0; j < bs; j++) {
			int a;	cin >> a;
			B.insert(a);
		}

		for (int j = 1; j < 5; j++) {
			Anum[j]=A.count(j);
			Bnum[j] = B.count(j);
		}
		int j;
		for (j = 4; j >= 1; j--) {
			if (Anum[j] == Bnum[j]) {
				continue;
			}
			else if (Anum[j] > Bnum[j]) {
				cout << "A\n";
				break;
			}
			else if (Anum[j] < Bnum[j]) {
				cout << "B\n";
				break;
			}
		}
		if (j == 0) cout << "D\n";
	}

	return 0;
}