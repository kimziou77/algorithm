#include <iostream>
using namespace std;
long long capsule[31][31];
int N;
long long dfs(int w,int h) {
	if (capsule[w][h])//���� �ִٸ�
		return capsule[w][h];//�� ���� ��ȯ���ش�.

	if (w == 0)	return 1;
	
	capsule[w][h] = dfs(w - 1, h + 1);//�Ѱ�¥�� �˾�

	//�ݰ��� ���� �� �ִٸ� �ݰ��� �Դ� ����� ���� �߰����ش�
	if (h > 0)
		capsule[w][h] += dfs(w, h - 1);//�ݰ�¥���˾�

	return capsule[w][h];
}

int main(void) {

	while (cin >> N && N != 0)
		cout<<dfs(N, 0)<<"\n";

	return 0;
}