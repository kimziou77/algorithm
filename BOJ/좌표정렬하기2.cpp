#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
bool comp(pii a, pii b) {
	if (a.second < b.second) // yÁÂÇ¥ Áõ°¡ ¼ø¼­
		return true;
	else if (a.second == b.second) // yÁÂÇ¥°¡ µ¿ÀÏÇÏ¸é
		return a.first < b.first; // xÁÂÇ¥ Áõ°¡ ¼ø¼­
	return false;
}
int main(void) {
	int N;	cin >> N;
	vector<pii> v;
	for (int i = 0; i < N; i++) {
		int a, b;	cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(),comp);
	for (auto i : v)
		printf("%d %d\n", i.first, i.second);
	return 0;
}