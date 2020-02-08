#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> v;
vector<int> K;
int min_cal = INT_MAX;

bool check(int a0,int k,int now) {//수열이 되는지 체크
	int num = now;
	for (int i = 2; i < n; i++) {
		int c = a0 + i * k;
		if (v[i] == c)
			continue;
		else if (v[i] == c + 1 || v[i] == c - 1) 
			num++;
		else {
			return false;
		}
	}
	if (min_cal > num) min_cal = num;
	return true;
}

int main(void) {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	//0번째를 그냥 시작했을 때
	{
		int k;
		{//1번째를 -1 했을 때
			//초항이 v[0] 공차가 k
			k = v[1] - 1 - v[0];
			check(v[0], k,1);
		}
		{//1번째를 +0 했을 때
			k = v[1] - v[0];
			check(v[0], k,0);
		}
		{//1번째를 +1 했을 때
			k = v[1] + 1 - v[0];
			check(v[0], k,1);
		}
	}

	//0번째를 +1하고 시작했을 때
	{
		int k;
		{//1번째를 -1 했을 때
			k = v[1] - 1 - v[0] - 1;
			check(v[0]+1, k,2);
		}
		{//1번째를 +0 했을 때
			k = v[1] - v[0] - 1;
			check(v[0]+1, k,1);
		}
		{//1번째를 +1 했을 때
			k = v[1] + 1 - v[0] - 1;
			check(v[0]+1, k,2);
		}
	}

	//0번째를 -1하고 시작했을 때
	{
		int k;
		{//1번째를 -1 했을 때
			k = v[1] - 1 - v[0] + 1;
			check(v[0]-1, k,2);
		}
		{//1번째를 +0 했을 때
			k = v[1] - v[0] + 1;
			check(v[0]-1, k,1);
		}
		{//1번째를 +1 했을 때
			k = v[1] + 1 - v[0] + 1;
			check(v[0]-1, k,2);
		}
	}
	if (min_cal == INT_MAX)
		cout << -1;
	else
		cout << min_cal;

	return 0;
}
