#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> now;
vector<int> change;

int N;
int answer = 0;

int click(vector<int> tmp,int i) {
	if(i-1>0)
		tmp[i - 1] = !tmp[i - 1];
	tmp[i] = !tmp[i];
	if((i+1)<N)
		tmp[i + 1] = !tmp[i + 1];
	answer++;//i번째 스위치를 눌러서 변화시킨다

}
int gridy(int index) {
	vector<int> tmp = now;
	if (index == N) {
		if (tmp[N - 1] == change[N - 1]) {
			return answer;
		}
		else {
			return -1;
		}
	}

	if (tmp[index - 1] == change[index - 1])
		return gridy(index + 1);
	else {
		click(tmp, index);
		return gridy(index + 1);
	}

}
int main(void) {
	cin >> N;//전구 개수
	
	now.resize(N,0);
	change.resize(N,0);

	for (int i = 0; i < N; i++)
		scanf("%1d", &now[i]);
	for (int i = 0; i < N; i++)
		scanf("%1d", &change[i]);



	//output : 상태를 만들기 위해 스위치 최소 몇번?
	return 0;
}