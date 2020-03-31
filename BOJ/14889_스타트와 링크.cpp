#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX_SIZE 21

using namespace std;
int N;
int power[MAX_SIZE][MAX_SIZE];
int gap = INT_MAX;
int power_gap(vector<int> & target) {
	int sum = 0;
	vector<bool> check(MAX_SIZE, false);
	for (auto s : target)
		check[s] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i] && check[j]) sum += power[i][j];
			if (!check[i] && !check[j]) sum -= power[i][j];
		}
	}
	return abs(sum);
}
void make_team(int idx, vector<int> start,vector<int> link) {
	if (start.size() == N / 2||link.size()==N/2) {
		vector<int>& target = (start.size() > link.size()) ? start : link;
		int tmp = power_gap(target);
		if (tmp < gap) gap = tmp;
		return;
	}

	start.push_back(idx);
	make_team(idx + 1, start,link);
	start.pop_back();

	link.push_back(idx);
	make_team(idx + 1, start, link);
	link.pop_back();

}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> power[i][j];
	make_team(0, {}, {});
	cout << gap;
	return 0;
}