#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<vector<int>> power;
int power_gap(vector<int>& s, vector<int> & l) {
	int s_sum = 0;
	int l_sum = 0;
	for (auto i : s)
		for (auto j : s)
			s_sum += power[i][j];

	for (auto i : l)
		for (auto j : l)
			l_sum += power[i][j];
	return abs(s_sum - l_sum);
}

int brutu(vector<int> s, vector<int> l,int index) {
	int ss, ll;
	if (s.size() + l.size() == N)//���λ���� �� N���̸� ����
		return power_gap(s, l);

	//index������
	s.push_back(index);
	ss=brutu(s, l,index+1);//s���� ���־�����
	s.pop_back();

	l.push_back(index);
	ll=brutu(s, l,index+1);//l���� �־��� ��
	l.pop_back();

	return min(ss, ll);
}

int main(void) {
	cin >> N;
	power.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> power[i][j];
	vector<int> start;
	vector<int> link;
	cout<<brutu(start, link,0);

	//�ɷ�ġ ������ �ּҰ� ���

	return 0;
}