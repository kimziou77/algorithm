#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> makeTable(string p) {
	int m = p.size();
	vector<int> table(m, 0);
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = table[j - 1];

		if (p[i] == p[j])
			table[i] = ++j;
	}
	return table;
}

int kmp(string s, string p) {
	auto table = makeTable(p);
	int parentSize = s.size();
	int patternSize = p.size();
	table[patternSize - 1] = 0;//���ڿ��� �߰��ߴٸ� �ٽ� 0���� ���ư��� �ϹǷ�

	int j = 0;//�ε����� 0���� ����
	int answer = 0;
	for (int i = 0; i < parentSize; i++) {//���ڿ� ó������ Ž���ϴµ�

		while (j > 0 && s[i] != p[j]) //j������ ��
			j = table[j - 1];//j���� ��� ���������� �����Ų��.

		if (s[i] == p[j]) {
			if (j == patternSize - 1) { //��� �­��ٸ�
				//cout << "ã�� ��ġ : " << i - petternSize + 1 << endl;
				j = 0;//�ٽ� �˻����
				answer++; // ���䰳�� ++
			}
			else {
				j++;
			}
		}
	}
	return answer;
}
int main(void) {
	string a; string b;
	getline(cin,a);
	getline(cin,b);

	cout<<kmp(a, b);
	
	return 0;
}