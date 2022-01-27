#include <iostream>
using namespace std;
int N, M;

//0��° ���̽�ũ�� x
bool DONT[10002][10002];//���� ������ȵǴ� ����


bool check(int i,int j ,int k) {
	return DONT[i][j] || DONT[i][k] || DONT[j][k];
}
int main(void) {
	int count = 0;
	cin >> N >> M;
	//���̽�ũ�� 3������

	//��������� �ȵǴ� ������ ��ȣ
	for (int i = 0; i < M; i++) {
		int a, b;	cin >> a >> b;
		DONT[a][b] = true;
		DONT[b][a] = true;
	}

	for (int i = 1; i <= N; i++)
		for (int j = i+1; j <= N; j++)
			for (int k = j+1; k <= N; k++)
				if (!check(i, j, k))
					count++;

	cout << count;
	return 0;
}