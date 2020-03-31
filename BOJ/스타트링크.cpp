#include <iostream>
#include <queue>
bool check[1000001];
using namespace std;
//건물은 1층부터 시작
int F, S, G, U, D;
void elevator(int node){
	queue<int> stairs;	stairs.push(node);	check[node] = true;
	int s, ns;
	int push = 0;
	while (!stairs.empty()) {
		int sz = stairs.size();
		for (int i = 0; i < sz; i++) {
			s = stairs.front();	stairs.pop();
			if (s == G) {
				while (!stairs.empty())	stairs.pop();
				cout << push;
				return;
			}
			ns = s + U;
			if (!check[ns] && ns<=G) {
				stairs.push(ns);
				check[ns] = true;
			}
			ns = s - D;
			if (!check[ns] && ns >= 1) {
				stairs.push(ns);
				check[ns] = true;
			}
		}
		push++;
	}
	cout << "use the stairs";
}
int main(void) {
	cin >> F >> S >> G >> U >> D;
	elevator(S);

	return 0;
}