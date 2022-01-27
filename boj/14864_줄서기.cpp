#include <iostream>
#include <vector>
using namespace std;

int N, M;
int main(void) {
	cin >> N >> M;
	vector<int> student(N + 1);
	vector<bool> check(N + 1,false);
	for (int i = 1; i <= N; i++)
		student[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		student[a]++; student[b]--;
	}
	for (int i = 1; i <= N; i++) {
		if (student[i]<0 || student[i]>N||check[student[i]]) {
			cout << -1;
			return 0;
		}
		check[student[i]] = true;
	}

	for (int i = 1; i <= N; i++)
		cout << student[i] << " ";

	return 0;
}
/*
�� �л��� 1���� N����
���� �ٸ� ��ȣ�� ���� ī��� �� �ϳ��� ������ �ִ�
�ڿ� �������鼭 �� ���� ��ȣ�� ī�带 ���� �л����� ����� �ϳ��� �������� ��� �޾Ҵ�

*/