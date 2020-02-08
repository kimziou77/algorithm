#pragma region test
//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#define MAX_LEN 10
//using namespace std;
//
//int main(void) {
//	int t = 3;
//	srand(time(NULL));
//	while (t--) {
//		int n = rand() % MAX_LEN + 1;
//		int k = rand() % MAX_LEN + 1;
//		cout << "N : " << n << " K : " << k << endl;
//		int min_len = n;
//
//		vector<int> v(n);
//		for (int i = 0; i < n; i++) {
//			v[i] = rand() % MAX_LEN + 1;
//		}
//		cout << "test vector random num init" << endl;
//		for (auto i : v) {
//			cout << i << " ";
//		}
//		cout << endl;
//		for (int i = 0; i < n; i++) {
//			int len = 0;
//			if (v[i] < k * i + 1) continue;
//			for (int j = 0; j < n; j++) {
//				if (v[j] - v[i] != (j - i) * k) len++;
//			}
//			if (min_len > len) min_len = len;
//		}
//
//		cout << min_len;
//		cout << "----------------------------------" << endl << endl;
//
//	}
//
//	return 0;
//}
#pragma endregion
#include <iostream>
#include <vector>
#define MAX_LEN 10
using namespace std;

int main(void) {
	int n, k;	cin >> n >> k;
	int min_len = n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		int len = 0;
		if (v[i] < k * i + 1) continue;
		for (int j = 0; j < n; j++) {
			if (v[j] - v[i] != (j - i) * k) len++;
		}
		if (min_len > len) min_len = len;
	}

	cout << min_len;

	return 0;
}