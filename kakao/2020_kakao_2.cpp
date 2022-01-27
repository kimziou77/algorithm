#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iterator>
using namespace  std;
vector<vector<int>> v;
set<int> judge;//list�� ������ ������ �Ǵ����ִ� set

void tokenize(string s) {
	s.pop_back();
	for (int i = 1; i < s.size(); i++) {
		vector<int> tmp;
		string k;
		if (s[i] == '{') {
			i++;
			while (s[i] != '}') {
				if (s[i] == ',') {
					int num = stoi(k);
					tmp.push_back(num);
					k = "";
					i++;
					continue;
				}
				k += s[i];
				i++;
			}
			int num = stoi(k);
			tmp.push_back(num);
			v.push_back(tmp);
		}
		else if (s[i] == '}') continue;
		else if (s[i] == ',') continue;
	}
}
bool comp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}
int main(void) {
	vector<int> answer;
	string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	tokenize(s);// to vector<vector<int>> v;

	sort(v.begin(), v.end(),comp);

	for (auto i : v) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}



	for (auto i : v) {
		for (auto j : i) {
			auto p = judge.insert(j);
			if (p.second) {//�ִµ� �����ߴٸ�,
				answer.push_back(j);
				break;
			}

		}
	}

	for (auto i : answer) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
/*
 pr=s.insert(k)

 s �����̳ʿ� k�� �����Ѵ�. pr�� ������ ���Ҹ� ����Ű�� �ݺ��ڿ� ���� ������ bool�� pair ��ü�̴�.
 insert�� �����ϸ�, list�� �߰����ش�.

*/