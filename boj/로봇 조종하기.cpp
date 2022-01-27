#include <iostream>
#include <climits>
#include <set>
#include <queue>
#define MAX_SIZE 1001
using namespace std;
using pii = pair<int, int>;
int N, M;
int max_price = INT_MIN;
int dn[] = { 1,0,0 };
int dm[] = { 0,-1,1 };
int map[MAX_SIZE][MAX_SIZE];
int price_map[MAX_SIZE][MAX_SIZE];
struct robot {
	int n, m;//������ġ
	int price;//���ݱ��� Ž���� �������� ��ġ��
	set<pii> check;//���ݱ��� Ž���� ������
};

void bfs(robot a14) {
	queue<robot> q;
	a14.check.insert({ a14.n,a14.m });
	q.push(a14);
	int n, m, nn, nm;

	while (!q.empty()) {
		int sz = q.size();
		if (sz > 10)	cout << "�޸𸮰��ƾƾƾ��ľƾ� "<<sz << endl;
		
		for (int i = 0; i < sz; i++) {
			robot b14 = q.front(); q.pop();
			n = b14.n;	m = b14.m;
			if (n == N - 1 && m == M - 1) {
				if (max_price < b14.price)
					max_price = b14.price;
			}

			for (int j = 0; j < 3; j++) {
				nn = n + dn[j];	nm = m + dm[j];
				if (nn<0 || nm<0 || nn>N - 1 || nm>M - 1) continue;
				if (b14.check.find({ nn,nm }) == b14.check.end()) {//���� Ž������ ���� �����̶��
					int tmp_price = b14.price + map[nn][nm];
					if (price_map[nn][nm] < tmp_price) {//�������� �湮�߰� price�� �װԴ� ���ٸ�..
						robot c14 = b14;
						c14.n = nn;
						c14.m = nm;
						c14.check.insert({ nn,nm });
						c14.price += map[nn][nm];
						price_map[nn][nm] = c14.price;
						q.push(c14);
					}
				}
			}
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	bfs({ 0,0, map[0][0]});
	cout << max_price;

	return 0;
}