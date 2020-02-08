#include <iostream>
#include <algorithm>
using namespace std;
int x, y, w, h;
int main(void) {
	cin >> x >> y >> w >> h;
	cout << min(min(abs(x - w), x),min(abs(y-h),y));
	return 0;
}