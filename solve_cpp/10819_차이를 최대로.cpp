#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(void) {
	int N;	cin >> N;
	int mx = INT_MIN;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	do {
		int sum = 0;

		for (int i = 0; i < N-1; i++)
			sum += abs(nums[i] - nums[i + 1]);

		if (mx < sum) mx = sum;

	} while (next_permutation(nums.begin(), nums.end()));
	cout << mx;
	return 0;
}