#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n, k;
vector<int> coin;
int check[101];
int min_coin_num = INT_MAX;
//int min_coin(int node) {
//	queue<int> q;	q.push(node);
//	int price = 0, num = 0;
//	while (!q.empty()) {
//		int sz = q.size();
//
//		for (int i = 0; i < sz; i++) {
//			price = q.front();	q.pop();
//			if (price == k) {
//				return num;
//			}
//
//			for (int j = 0; j < coin.size(); j++) {
//				price += coin[j];
//				q.push(price);
//			}
//		}
//		num++;
//	}
//	return -1;
//}

void dfs(int money,int index,int num) {
	if (money > k) return;//가지치기,
	if (money == k) {
		if (min_coin_num > num)
			min_coin_num = num;
		return;
	}
	for (int i = 0; i < coin.size(); i++) {
		//if (check[i] == true) continue;
		check[i]++;
		dfs(money + coin[i], i, num + 1);
		check[i]--;
	}

}

int main(void) {
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end());
	reverse(coin.begin(), coin.end());

	dfs(0,0,0);

	if (min_coin_num == INT_MAX)
		cout << -1;
	else
		cout << min_coin_num;

	return 0;
}