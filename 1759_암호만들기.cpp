#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<char> consonant;//자음
vector<char> vowels;//모음
vector<char> answer;
int L, C;
vector<char> c;
bool check[16];
bool isVowels(char a) {
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}
void passwd(int idx, int len) {
	//기저사례
	if (len > L) return;
	if (len == L) {//L개 모두 선택했다면 끝
		if (vowels.size() < 1) return;
		if (consonant.size() < 2) return;
		for (auto i : answer)
			printf("%c", i);
		printf("\n");
		return;
	}

	for (int i = idx; i < c.size(); i++) {

		if (isVowels(c[i]) && !check[i]) {//모음
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
			consonant.push_back(c[i]);//자음
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
	암호는 서로다른 L개의 알파벳 소문자로 구성
	알파벳은 증가하는 순서로 배열됨
	가능한 문자의 종류 C개
	------
	3 <= L,C <= 15

	가능한 문자 C개로 만들 수 있는 L개의 암호,
	최소 한개의 모음  a i u e o
	최소 두개의 자음

	->가능성 있는 암호들을 모두 출력

	브루트 포스 // 가지치기! 기저사례
*/