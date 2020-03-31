#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool check[26];
int main(void) {
	string s;	cin >> s;
	stack<char> stk;
	stack<char> tmp;
	int num = 0;
	for (int i = 0; i < 52; i++) {
		if (check[s[i]-'A'] == false) {//an alphabet not yet entered 
			check[s[i]-'A'] = true;
			stk.push(s[i]);
		}
		else{ //s[i] exist in the stack
			if (!stk.empty()) {
				while (stk.top() != s[i]) {
					tmp.push(stk.top());	stk.pop();
					num++;
				}
				stk.pop();
			}
			while (!tmp.empty()) {
				stk.push(tmp.top());	tmp.pop();
			}
		}
	}
	cout << num;
	return 0;
}
