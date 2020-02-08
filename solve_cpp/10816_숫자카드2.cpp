#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> card(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;	cin >> num;
		cout<<upper_bound(card.begin(), card.end(), num)-lower_bound(card.begin(), card.end(), num)<<" ";
	}

	return 0;
}

