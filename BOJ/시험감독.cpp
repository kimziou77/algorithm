#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, B;
double C;
int main(void) {
	cin >> N;
	vector<int> A(N);	int max = 0;

	for (int i = 0; i < N; i++)//시험장에 들어가는 학생 수
		cin >> A[i];

	cin >> B >> C;

	long long sum = 0;

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0)
			sum += ceil(A[i] / C);
	}
	cout << sum+N;
	return 0;
}