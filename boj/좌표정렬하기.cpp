#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
bool comp(pii a, pii b) {
	if (a.first < b.first) // x��ǥ ���� ����
		return true;
	else if (a.first == b.first) // x��ǥ�� �����ϸ�
		if (a.second < b.second) // y��ǥ ���� ����
			return true;
	return false;
}
int main(void) {
	int N;	cin >> N;
	vector<pii> v;
	for (int i = 0; i < N; i++) {
		int a, b;	cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i.first << " " << i.second << endl;
	return 0;
}