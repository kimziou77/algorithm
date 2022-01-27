#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> v;
vector<int> K;
int min_cal = INT_MAX;

bool check(int a0,int k,int now) {//������ �Ǵ��� üũ
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

	//0��°�� �׳� �������� ��
	{
		int k;
		{//1��°�� -1 ���� ��
			//������ v[0] ������ k
			k = v[1] - 1 - v[0];
			check(v[0], k,1);
		}
		{//1��°�� +0 ���� ��
			k = v[1] - v[0];
			check(v[0], k,0);
		}
		{//1��°�� +1 ���� ��
			k = v[1] + 1 - v[0];
			check(v[0], k,1);
		}
	}

	//0��°�� +1�ϰ� �������� ��
	{
		int k;
		{//1��°�� -1 ���� ��
			k = v[1] - 1 - v[0] - 1;
			check(v[0]+1, k,2);
		}
		{//1��°�� +0 ���� ��
			k = v[1] - v[0] - 1;
			check(v[0]+1, k,1);
		}
		{//1��°�� +1 ���� ��
			k = v[1] + 1 - v[0] - 1;
			check(v[0]+1, k,2);
		}
	}

	//0��°�� -1�ϰ� �������� ��
	{
		int k;
		{//1��°�� -1 ���� ��
			k = v[1] - 1 - v[0] + 1;
			check(v[0]-1, k,2);
		}
		{//1��°�� +0 ���� ��
			k = v[1] - v[0] + 1;
			check(v[0]-1, k,1);
		}
		{//1��°�� +1 ���� ��
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
