#include <iostream>
#include <vector>
using namespace std;
int n, s;
vector<int> v;
int answer = 0;
void brutu(int b, int sum,int check) {
	//���ο� ���Ұ� �߰��Ǿ���, �� ���� s������
	if (check==1&&sum == s)	answer++;
	if (b >= n) return;

	//b���ε����� �ִ´�
	brutu(b + 1, sum+v[b],1);

	//b���ε����� ���� �ʴ´�.
	brutu(b + 1, sum, 0);
}

int main(void) {
	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	brutu(0, 0,0);//0��° �ε����� ����, ���� 0
	cout << answer;

	return 0;
}