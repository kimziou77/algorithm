#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> T;
vector<int> P;
int N;
long long pay[1500001];//���� ��� 0��

void dp() {
	for (int i = 0; i < N; i++) {//�ε��� ���� Ž��
		if (i - 1 > 0 && pay[i] < pay[i - 1])
			pay[i] = pay[i - 1];
		int tmp = pay[i]+P[i];//���� i�Ϸκ��� T���Ŀ� ���� pay�� ���� P�� �߰�

		if (i + T[i] <= N && pay[i + T[i]] < tmp) {//���� �߰��� �ݾ��� �� ũ�ٸ�
				pay[i + T[i]] = tmp;//����
		}
	}
	cout<<max(pay[N], pay[N - 1]);
}
int main(void) {
	//N+1��° ���ÿ� ���� �� �ִ� �ִ� �ݾ�
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;	cin >> a >> b;
		T.push_back(a); P.push_back(b);
	}
	dp();
	return 0;
}