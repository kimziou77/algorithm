#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main(void) {
	cin >> N;
	vector<int> min_arr(3, 0);
	vector<int> max_arr(3, 0);
	
	for (int i = 1; i <= N; i++) {
		int a, b, c;	cin >> a >> b >> c;
		int max_tmp[3] = { max_arr[0],max_arr[1],max_arr[2] };
		int min_tmp[3] = { min_arr[0],min_arr[1],min_arr[2] };

		min_arr[0] = min(min_tmp[0], min_tmp[1]) + a;
		max_arr[0] = max(max_tmp[0], max_tmp[1]) + a;

		min_arr[1] = min(min(min_tmp[0], min_tmp[1]), min_tmp[2]) + b;
		max_arr[1] = max(max(max_tmp[0], max_tmp[1]), max_tmp[2]) + b;

		min_arr[2] = min(min_tmp[1], min_tmp[2]) + c;
		max_arr[2] = max(max_tmp[1], max_tmp[2]) + c;
	}

	cout << max(max(max_arr[0], max_arr[1]), max_arr[2]) << " "
		 << min(min(min_arr[0], min_arr[1]), min_arr[2]);

	return 0;
}