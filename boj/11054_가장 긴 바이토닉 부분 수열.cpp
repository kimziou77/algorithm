#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pii {
	int down, up;
};
int main(void) {

	int N;	cin >> N;
	vector<int> v(N);
	vector<pii> d(N, { 0,1 });
	int bitonic = 1;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {//더 큰 수라면
				d[i].up = max(d[i].up, d[j].up + 1);
			}
			if (v[N-1- j] < v[N-1-i]) {//더 큰 수라면
				d[N-1-i].down = max(d[N-1-i].down, d[N-1-j].down + 1);
			}
		}
		for (int j = N-1; j > i ; j--) {
			if (v[j] < v[i]) {//더 작은 수라면
				d[i].down = max(d[i].down, d[j].down + 1);
			}
		}
		cout << "up" << endl;
		for (int i = 0; i < N; i++) {
			cout << d[i].up << " ";
		}
		cout << endl;
		cout << "down" << endl;
		for (int i = 0; i < N; i++) {
			cout << d[i].down << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		int tot = d[i].up + d[i].down;
		if (bitonic < tot) {
			bitonic = tot;
		}
	}

	cout << bitonic;
	return 0;
}