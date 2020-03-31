#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
vector<string> token;
vector<int> fin;
int main(void) {
	//-기준으로 잘라서 다 더하고 계산
	string s,b;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {// -기준으로 잘라서 token에 넣어둔다.
			string a = s.substr(0,i);
			b = s.substr(i + 1, s.size() - i);
			cout << "a : " << a << " b : " << b << endl;
			token.push_back(a);
			s = b; i = 0;
		}
	}
	token.push_back(s);
	cout << "token화 된 token을 출력해봅시다." << endl;
	for (auto i : token)
		cout << i << " ";
	cout << endl;
	cout << "--------------------------------------" << endl;


	for (int i = 0; i < token.size(); i++) {
		int num,sum=0;
		stringstream ss(token[i]);
		while (ss >> num) {
			sum += num;
		}
		fin.push_back(sum);
	}
	cout << "계산된 fin을 출력해봅니다." << endl;
	for (auto i : fin)
		cout << i << " ";
	cout << endl;
	cout << "--------------------------------------" << endl;


	int first = 0;
	if(fin.size()>0) 
		first = fin[0];

	for (int i = 1; i < fin.size(); i++) {
		first -= fin[i];
	}
	cout << first;
	return 0;
}