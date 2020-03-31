#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//우선순위는 앞쪽에서빌리는 순서대로

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	vector<int> p(n, 1);//모두 1개씩 가지고 있는 채로 시작.
		//n명 학생들이 가지고 있는 체육복의 개수를 표현한 벡터

	for (auto i : reserve)//여분의 체육복을 가진 친구들
		p[i - 1]++;

	for (auto i : lost) {
		p[i - 1]--;
		if (i - 2 > 0 && p[i - 2] > 1) {//범위검사후ㅡ 여분의 체육복을 가진 친구인지 확인(앞)
			p[i - 2]--;
			p[i - 1]++;
		}
		else if (i - 1 < n && p[i] > 1) {//(뒤)
			p[i]--;
			p[i - 1]++;
		}
		else {  //체육복을 빌리지 못함 - 체육수업 못들음
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