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

	// �ϰ� �������� Ű�� ���� 100�� �ȴ�


	//�ϰ��������� Ű�� ������������ ���
	sort(nanjeng.begin(), nanjeng.end());
	for (auto i : nanjeng)
		cout << i << endl;

	return 0;
}