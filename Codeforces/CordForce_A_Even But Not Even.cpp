#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> odd_idx;
bool check_ebne(string & s) {

	//마지막 숫자가 홀수일때까지 뺀다.
	for (int last_num = s[s.size() - 1] - '0'; s.size() > 0 && !(last_num & 1);) {
		last_num = s[s.size() - 1];
		s.pop_back();
	}
	
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - '0';
		if (num & 1) {
			odd_idx.push_back(i);
			if (i + 1 < s.size() && s[i + 1] - '0' == 0)
				odd_idx.push_back(i+1);
			i++;
		}
		sum += num;
	}
	//각 자리 숫자 합이 홀수이면 false
	if (sum & 1||s.size()==0)
		return false;

	return true;
}
void print_ebne(string & s) {
	if (odd_idx.size() == 0||s.size()==0) {
		cout << -1<<"\n";
	}
	else {
		for (int i = 0,index=0; i < s.size(); i++) {
			if (i == odd_idx[index++]) {
				continue;
			}
			if (odd_idx[index] == 0) {
				index++;
				continue;
			}
			cout << s[i];
		}
		cout << "\n";
	}
}
int main(void) {
	int t;	cin >> t;
	while (t--) {
		odd_idx.clear();
		int n;	cin >> n;
		string s; cin >> s;
		if (!check_ebne(s))
			print_ebne(s);
		else
			cout << s << "\n";
	}
	return 0;
}