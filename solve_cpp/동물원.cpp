#include <iostream>
using namespace std;

int N;
long long num;
int lion[3][100001];//[위,아래,NULL]*[i]번쨰 타일
void dp() {
	//초기값
	lion[0][1] = 1;	lion[1][1] = 1;	lion[2][1] = 1;
	for (int i = 2; i <= N; i++) {
		lion[0][i] = (lion[0][i - 1] + lion[1][i - 1] + lion[2][i - 1]) % 9901;
		lion[1][i] = (lion[0][i - 1] + lion[2][i - 1]) % 9901;
		lion[2][i] = (lion[0][i - 1] + lion[1][i - 1]) % 9901;
	}
	int sum = (lion[0][N] + lion[1][N] + lion[2][N]) % 9901;
	cout << sum;
}
int main(void) {
	cin >> N;
	dp();
	return 0;
}