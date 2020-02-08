#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K;

int main(void) {
	cin >> N >> K;	K;
	deque<int> d(N);
	vector<int> v;
	for (int i = 0; i < N; i++) {
		d[i] = i + 1;
	}
	cout << "<";
	while (!d.empty()) {
		for (int i = 0; i < K - 1; i++) {
			d.push_back(d.front());
			d.pop_front();
		}
		cout << d.front();
		if (d.size() != 1) {
			cout << ", ";
		}
		d.pop_front();
	}
	
	cout << ">";
	return 0;
}