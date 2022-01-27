#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MAX_SIZE 1000000001

int s, t;
set<long long> check;
bool bfs(int node) {
	queue< pair<int, string>> q;	q.push({ node,"" });
	check.insert(node);
	string oper;
	long long bc;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			bc = q.front().first;	
			oper = q.front().second;
			check.insert(bc);
			if (bc == t) {
				for (auto p : oper)
					cout << p;
				while (!q.empty())q.pop();
				return true;
			}
			q.pop();

			//4¿¬»ê
			if (bc * bc < MAX_SIZE && (check.find(bc * bc) == check.end())) {
				q.push({ bc * bc,oper+'*' });
			}
			if (bc + bc < MAX_SIZE && (check.find(bc + bc) == check.end())) {
				q.push({ bc + bc,oper+'+' });
			}
			if (bc - bc > 0 && (check.find(bc - bc) == check.end())) {
				q.push({ bc - bc,oper+'-' });
			}
			if (bc != 0 && (check.find(bc / bc) == check.end())) {
				q.push({ bc / bc,oper+'/' });
			}
		}
	}
	return false;
}
int main(void) {
	cin >> s >> t;
	if (s == t)
		cout << 0;
	else if (!bfs(s))
		cout << -1;

	return 0;
}