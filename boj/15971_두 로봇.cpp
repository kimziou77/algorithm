#include <iostream>
#include <vector>
using namespace std;
struct pii {
	int node;
	int len;
};
vector<pii> room[100'001];
vector<int> mv;
bool check[100'001];
int N, A, B;
int sum = 0;
int dfs(int node) {
	check[node] = true;
	//break point
	if (node == B && mv.size() > 0) {
		int max_len = mv[0];
		for (int i : mv) {
			sum += i;
			if (max_len < i) max_len = i;
		}
		sum -= max_len;
		return sum;
	}
	for (int i = 0; i < room[node].size(); i++) {
		pii next = room[node][i];
		if (!check[next.node]) {
			check[next.node] = true;
			mv.push_back(next.len);

			int value = dfs(next.node);
			if (sum > 0) return value;

			mv.pop_back();
			check[next.node] = false;
		}
	}
	return 0;
	//room[node];//node번 에 연결된 간선들과 길이정보
}
int main(void) {
	cin >> N >> A >> B;
	for (int i = 0; i < N - 1; i++) {
		int a, b, L;	cin >> a >> b >> L;
		room[a].push_back({ b,L });//a -(L)- b
		room[b].push_back({ a,L });//b -(L)- a
	}
	cout << dfs(A);
	return 0;
}

/*
5 1 1
1 2 1
2 3 2
3 4 3
4 5 4

*/