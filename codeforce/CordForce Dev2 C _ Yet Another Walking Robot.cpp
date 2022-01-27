#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct robot {
	vector<moving> v;//�κ��� ��� �迭
	//i��° �ε������� ������� �̵��ؿԴ� ���
	robot(int n, string s) {
		v.resize(n);
		for (int i = 0; i < s.size(); i++) {
			if (i > 0) v[i] = v[i - 1];
			switch (s[i]) {
			case 'L':
				v[i].L++;
				break;
			case 'R':
				v[i].R++;
				break;
			case 'U':
				v[i].U++;
				break;
			case 'D':
				v[i].D++;
				break;
			}
		}
	}
};
struct moving {
	int L=0,U=0,R=0,D=0;
};
int main(void) {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		string s;	cin >> s;
		robot R(n,s);

	}

	return 0;
}