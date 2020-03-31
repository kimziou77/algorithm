#include <iostream>
using namespace std;
using ll = long long;
ll cal(ll a, ll b,char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		return a / b;
	case '*':
		return a * b;
	}
}
int main(void) {
	int T;	cin >> T;
	while (T--) {
		ll a, b,ans; char op, op2;
		cin >> a >> op >> b >> op2 >> ans;
		if (ans == cal(a, b,op))
			printf("correct\n");
		else
			printf("wrong answer\n");
	}

	return 0;
}