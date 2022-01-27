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
			//�ش� ���ڰ� ���� ���� ���� �����ϴ� �迭
			alpha[s[j] - 'A'] += jari;
		}
	}
	int sum = 0;
	sort(alpha.begin(), alpha.end(),greater<int>());//ū ������� ������ �Ǿ�����.
	for (int i = 0,j=9; i < alpha.size(); i++) {
		if(alpha[i]>0)
			sum+=alpha[i] * j--;
	}
	cout << sum;

	return 0;
}