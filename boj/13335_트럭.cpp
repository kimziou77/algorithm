#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, w, L;
int main(void) {
	cin >> n >> w >> L;
	vector<int> truc(n);
	deque<int> q(w,0);
	
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> truc[i];

	int time = 0;
	for (int i = 0;i<n; time++) {
		sum -= q.front();
		q.pop_front();
		if ( sum + truc[i] <= L) {
			q.push_back(truc[i++]);
			sum += q.back();
		}
		else {
			q.push_back(0);
		}
	}
	
	cout << time+w;
	return 0;
}