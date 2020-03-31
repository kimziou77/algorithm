#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, p;
vector<int> getPi(string a) {
	vector<int> pi(a.size(), 0);
	for (int i = 1,j=0; i < a.size(); i++) {
		while(j > 0 && a[i] != a[j])
			j = pi[j - 1];

		if (a[i] == a[j])
			pi[i] = ++j;
	}
	return pi;
}
int kmp(string s, string p) {
	vector<int> pi = getPi(s);
	for (int i = 0,j=0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == p.size() - 1)
				return 1;
			j++;
		}
	}
	return 0;
}
int main(void) {
	cin >> s >> p;
	cout << kmp(s, p);
	return 0;
}