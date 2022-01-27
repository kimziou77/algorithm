#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
	int t;	cin >> t;
	while (t--) {
		int s;	cin >> s;
		int pay_back=0,sum=0,tmp=s;

		while (tmp>=10) {
			pay_back = tmp / 10;
			sum+=pay_back;
			tmp %= 10;
			tmp += pay_back;
		}
		cout << s+sum << "\n";
	}
	return 0;
}