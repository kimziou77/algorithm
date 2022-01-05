#include <iostream>
#include <string>
int MAX_LEN = 998244353;
using namespace std;
int main(void) {
	int T;	cin >> T;
	while (T--) {
		int seg,len=0;	cin >> seg;
		string s;
		while (seg) {
			if (seg>6 && len >= MAX_LEN) {
				s.insert(s.begin(), '9');
				seg -= 6;
			}
			if (seg > 5 && len < MAX_LEN) {
				s.insert(s.end(), '71');
				len += 2;
				seg -= 5;
			}
		}
	}
	return 0;
}