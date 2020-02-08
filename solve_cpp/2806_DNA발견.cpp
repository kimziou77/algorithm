#pragma region first
//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <climits>
//using namespace std;
//int N;
//vector<char> s;
//int sol(char now, int num, int index) {
//	int one = INT_MAX, all = INT_MAX;
//	if (index == N && now == 'A') {
//		//cout << "idx " << index << " num : " << num << " now : " << now << endl;
//		return num;
//	}
//	else if (index == N && now == 'B'){	
//		//cout << "idx " << index << " num : " << num << " now : " << now << endl;
//		return num + 1;
//	}
//
//	for (int i = index; i < N; i++) {
//		if (i == N - 1 && now == 'B')
//			num += 1;
//		if (now != s[i]) {
//			//하나를 뒤집거나 앞에있는 전부를 뒤집는다.
//			char tmp = now;
//			all = sol(tmp, num + 1, i + 1);
//
//			(now == 'A') ? (now = 'B') : (now = 'A');
//			one = sol(now, num + 1, i + 1);
//			num=min(one, all);
//			//cout << "one ; " << one << " all : " << all << endl;
//			if (i == N - 1 && now == 'B') 
//				num += 1;
//			break;
//		}
//
//	}
//	return num;
//}
//int main(void) {
//	cin >> N;
//	s.resize(N);
//	
//	for (int i = 0; i < N; i++) {
//		scanf(" %1c", &s[i]);
//	}
//	cout<<sol(s[0], 0, 1);
//	return 0;
//}
#pragma endregion

#include <iostream>
#include <string>
#include <algorithm>
#define A 0
#define B 1
using namespace std;
int D[1000001][2]; //x번째 인덱스에서 A인 경우 B인경우
int main(void) {
	int N;	cin >> N;
	string s;	cin >> s;
	int dna = s[0] - 'A';

	if (dna==A) {
		D[0][A] = 0;	D[0][B] = 1;
	}
	else if (dna==B){
		D[0][A] = 1;	D[0][B] = 0;
	}

	for (int i = 1; i < s.length(); i++) {
		dna =  s[i] - 'A';
		D[i][dna] = min(D[i - 1][dna], D[i - 1][!dna] + 1);
		D[i][!dna] = min(D[i - 1][!dna] + 1, D[i - 1][dna] + 1);
	}
	cout << D[s.length() - 1][A];

	return 0;
}

/*
		D[i][A] = min(D[i-1][A],D[i-1][B]+1);
		//D[i][A] i번째 일에 모두 A이기 위한 돌연변이 수
		D[i][B] = min(D[i-1][B],D[i-1][A]+1);
*/
