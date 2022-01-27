#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int N;	
int max_num = INT_MIN;
int min_num = INT_MAX;
vector<int> nums;
vector<int> oper;
int cal(int op,int num1, int num2) {
	switch (op) {
	case 0 :
		return num1 + num2;
	case 1:
		return num1 - num2;
	case 2:
		return num1 * num2;
	case 3: {
		if (num1 < 0)
			return -(abs(num1) / num2);
		else
			return num1 / num2;
	}
	}
}
void sol(int index, vector<int> op, int result) {
	if (index == N-1) {
		if (min_num > result)
			min_num = result;
		if (max_num < result)
			max_num = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] <= 0) continue;//연산자가 없으면 다른연산 진행
		op[i]--;
		int num=cal(i,result,nums[index+1]);//index번째 계산
		sol(index+1,op, num);
		op[i]++;
	}
}
int main(void) {
	cin >> N;
	nums.resize(N);
	oper.resize(4);
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	sol(0, oper, nums[0]);
	cout << max_num << endl << min_num;
	return 0;
}