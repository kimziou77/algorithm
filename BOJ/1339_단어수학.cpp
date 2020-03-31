#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N;
int main(void) {
	cin >> N;
	vector<string> v(N);
	vector<int> alpha(26, 0);
	for (int i = 0; i < N; i++) {
		string s;	cin >> s;
		reverse(s.begin(), s.end());
		for (int j = 0, jari=1; j < s.size(); j++, jari*=10) {
			//해당 문자가 가진 수의 합을 저장하는 배열
			alpha[s[j] - 'A'] += jari;
		}
	}
	int sum = 0;
	sort(alpha.begin(), alpha.end(),greater<int>());//큰 순서대로 정렬이 되어있음.
	for (int i = 0,j=9; i < alpha.size(); i++) {
		if(alpha[i]>0)
			sum+=alpha[i] * j--;
	}
	cout << sum;

	return 0;
}