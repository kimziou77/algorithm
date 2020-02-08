#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	vector<int> v(9);
	vector<int> nanjeng;

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	// 일곱 난쟁이의 키의 합이 100이 된다


	//일곱난쟁이의 키를 오름차순으로 출력
	sort(nanjeng.begin(), nanjeng.end());
	for (auto i : nanjeng)
		cout << i << endl;

	return 0;
}