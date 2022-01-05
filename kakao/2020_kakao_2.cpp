#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iterator>
using namespace  std;
vector<vector<int>> v;
set<int> judge;//list에 담을지 말지를 판단해주는 set

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
			if (p.second) {//넣는데 성공했다면,
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

 s 컨테이너에 k를 삽입한다. pr은 삽입한 원소를 가리키는 반복자와 성공 여부의 bool인 pair 객체이다.
 insert에 성공하면, list에 추가해준다.

*/