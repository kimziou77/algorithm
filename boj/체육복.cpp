#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//�켱������ ���ʿ��������� �������

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	vector<int> p(n, 1);//��� 1���� ������ �ִ� ä�� ����.
		//n�� �л����� ������ �ִ� ü������ ������ ǥ���� ����

	for (auto i : reserve)//������ ü������ ���� ģ����
		p[i - 1]++;

	for (auto i : lost) {
		p[i - 1]--;
		if (i - 2 > 0 && p[i - 2] > 1) {//�����˻��Ĥ� ������ ü������ ���� ģ������ Ȯ��(��)
			p[i - 2]--;
			p[i - 1]++;
		}
		else if (i - 1 < n && p[i] > 1) {//(��)
			p[i]--;
			p[i - 1]++;
		}
		else {  //ü������ ������ ���� - ü������ ������
			answer--;
		}
	}

	return answer;
}
int main(void) {
	vector<int> lost = { 3 };
	vector<int> reserve = { 1};
	cout<<solution(3, lost, reserve);
	return 0;
}