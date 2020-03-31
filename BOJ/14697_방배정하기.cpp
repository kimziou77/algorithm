#include <iostream>
#include <climits>
using namespace std;
int main(void) {
	int a, b, c, n;	cin >> a >> b >> c >> n;
	int tmp = INT_MIN;

	for (int i = 0; i<300; i++){
		for (int j = 0; j<300; j++) {
			for (int k = 0; k<300; k++) {
				tmp = a * i + b * j + c * k;
				if (tmp > n) break;
				if (tmp== n) {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}