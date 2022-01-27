#include <iostream>
#include <queue>
#include <cstdio>
#define MAX_SIZE 1001
using namespace std;
int N, M, K;

int map[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE][11];

int dn[] = { 0,-1,1,0,0 };
int dm[] = { 0,0,0,1,-1 };
struct pos {
	int n, m;//������ġ
	int destroy;//���μ�ȸ��
	int cnt;//���ȸ�� �ִ�1ȸ
};
int bfs(pos node) {
	int day = 1;//�� ��
	queue<pos> q;	q.push(node);
	check[node.n][node.m][node.destroy] = true;
	int nn, nm, n, m;
	int dis = 1;
	bool destory;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pos tmp = q.front();
			n = tmp.n;	m = tmp.m;	q.pop();

			if (n == N - 1 && m == M - 1) {
				while (!q.empty())q.pop();
				return dis;
			}

			for (int j = 0; j < 5; j++) {
				nn = n + dn[j];	nm = m + dm[j];
				if (nn<0 || nm<0 || nn>N - 1 || nm>M - 1) continue;
				
				if (!check[nn][nm][tmp.destroy]) {//�������� �ʾҴٸ�
					if (map[nn][nm] == 0) {
						q.push({ nn,nm,tmp.destroy ,0});
						check[nn][nm][tmp.destroy] = true;
					}
					if (map[nn][nm] == 1 && tmp.destroy < K && day == 1) {//���ε� ���� �� �νǼ� �ְ� ���̸�
						q.push({ nn,nm,tmp.destroy + 1 ,0});	//���� �μ��� �־��ش�.
						check[nn][nm][tmp.destroy] = true;
					}
				}
				//�湮���ο� �������
				if (j == 0 && tmp.cnt == 0) { // �ڸ����� ��������� ���� ����
					q.push({ nn,nm,tmp.destroy,1 });//�ѹ� ����Ű��, �ٽ� ť�� �ִ´�.
				}
			}
		}
		dis++;
		day *= (-1);
	}
	return -1;
}
int main(void) {

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	cout << bfs({ 0,0,0,0 });

	return 0;
}
