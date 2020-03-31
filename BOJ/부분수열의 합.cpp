#include <iostream>
#include <vector>
using namespace std;
int n, s;
vector<int> v;
int answer = 0;
void brutu(int b, int sum,int check) {
	//새로운 원소가 추가되었고, 그 합이 s였을때
	if (check==1&&sum == s)	answer++;
	if (b >= n) return;

	//b번인덱스를 넣는다
	brutu(b + 1, sum+v[b],1);

	//b번인덱스를 넣지 않는다.
	brutu(b + 1, sum, 0);
}

int main(void) {
	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	brutu(0, 0,0);//0번째 인덱스로 시작, 합은 0
	cout << answer;

	return 0;
}