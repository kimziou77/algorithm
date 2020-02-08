#include <iostream>
using namespace std;
long long capsule[31][31];
int N;
long long dfs(int w,int h) {
	if (capsule[w][h])//값이 있다면
		return capsule[w][h];//그 값을 반환해준다.

	if (w == 0)	return 1;
	
	capsule[w][h] = dfs(w - 1, h + 1);//한개짜리 알약

	//반개도 먹을 수 있다면 반개를 먹는 경우의 수를 추가해준다
	if (h > 0)
		capsule[w][h] += dfs(w, h - 1);//반개짜리알약

	return capsule[w][h];
}

int main(void) {

	while (cin >> N && N != 0)
		cout<<dfs(N, 0)<<"\n";

	return 0;
}