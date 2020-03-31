#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> T;
vector<int> P;
int N;
long long pay[1500001];//현재 모두 0원

void dp() {
	for (int i = 0; i < N; i++) {//인덱스 순차 탐색
		if (i - 1 > 0 && pay[i] < pay[i - 1])
			pay[i] = pay[i - 1];
		int tmp = pay[i]+P[i];//현재 i일로부터 T일후에 현재 pay로 부터 P값 추가

		if (i + T[i] <= N && pay[i + T[i]] < tmp) {//새로 추가된 금액이 더 크다면
				pay[i + T[i]] = tmp;//갱신
		}
	}
	cout<<max(pay[N], pay[N - 1]);
}
int main(void) {
	//N+1일째 퇴사시에 받을 수 있는 최대 금액
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;	cin >> a >> b;
		T.push_back(a); P.push_back(b);
	}
	dp();
	return 0;
}