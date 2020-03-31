#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct score {
	int p, m;//서류, 면접
};
bool comp(score a, score b) {
	return a.p < b.p;
}
int main(void) {
	int T;	cin >> T;
	while (T--) {
		int N;	cin >> N;
		int num = N;
		vector<score> worker(N);

		for (int i = 0; i < N; i++)
			cin >> worker[i].p >> worker[i].m;

		sort(worker.begin(), worker.end(), comp);
		score tmp = worker[0];

		for (int i = 1; i < N; i++) {
			if (tmp.m >= worker[i].m)
				tmp = worker[i];
			else
				num--;
		}
		cout << num << "\n";

	}
	return 0;
}