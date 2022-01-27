#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<char> consonant;//����
vector<char> vowels;//����
vector<char> answer;
int L, C;
vector<char> c;
bool check[16];
bool isVowels(char a) {
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}
void passwd(int idx, int len) {
	//�������
	if (len > L) return;
	if (len == L) {//L�� ��� �����ߴٸ� ��
		if (vowels.size() < 1) return;
		if (consonant.size() < 2) return;
		for (auto i : answer)
			printf("%c", i);
		printf("\n");
		return;
	}

	for (int i = idx; i < c.size(); i++) {

		if (isVowels(c[i]) && !check[i]) {//����
			check[i] = true;
			vowels.push_back(c[i]);
			answer.push_back(c[i]);

			passwd(i + 1 , len + 1);

			answer.pop_back();
			vowels.pop_back();
			check[i] = false;
		}
		else if(!isVowels(c[i])&&!check[i]) {
			check[i] = true;
			consonant.push_back(c[i]);//����
			answer.push_back(c[i]);

			passwd(i + 1, len + 1);

			answer.pop_back();
			consonant.pop_back();
			check[i] = false;
		}
	}


}
int main(void) {

	cin >> L >> C;
	c.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	passwd(0, 0);
	return 0;
}
/*
	��ȣ�� ���δٸ� L���� ���ĺ� �ҹ��ڷ� ����
	���ĺ��� �����ϴ� ������ �迭��
	������ ������ ���� C��
	------
	3 <= L,C <= 15

	������ ���� C���� ���� �� �ִ� L���� ��ȣ,
	�ּ� �Ѱ��� ����  a i u e o
	�ּ� �ΰ��� ����

	->���ɼ� �ִ� ��ȣ���� ��� ���

	���Ʈ ���� // ����ġ��! �������
*/