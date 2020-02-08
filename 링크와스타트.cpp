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
	if (s.size() + l.size() == N)//모인사람이 총 N명이면 리턴
		return power_gap(s, l);

	//index번쨰를
	s.push_back(index);
	ss=brutu(s, l,index+1);//s팀에 ㅇ넣었을때
	s.pop_back();

	l.push_back(index);
	ll=brutu(s, l,index+1);//l팀에 넣었을 때
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

	//능력치 차이의 최소값 출력

	return 0;
}