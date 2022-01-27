#include <iostream>
using namespace std;
int main(void) {
	int a, b, c;
	while (cin >> a >> b >> c && a != 0 && b != 0 && c != 0) {
		int aa = a * a, bb = b * b, cc = c * c;
		if (aa + bb == cc || aa + cc == bb || bb + cc == aa)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}