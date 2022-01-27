#include <iostream>
#include <algorithm>
#define MAX_SIZE 501
using namespace std;

int Bamboo[MAX_SIZE][MAX_SIZE];
int dis[MAX_SIZE][MAX_SIZE];
bool check[MAX_SIZE][MAX_SIZE];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int n, max_life;
struct pii {
	int r, c;
};

int dfs(pii node) {
	int r = node.r;
	int c = node.c;
	if (r<0 || c<0 || r>n - 1 || c>n - 1)	return 0;
	if (dis[r][c] != 0)		return dis[r][c];

	//�� �� �� �� max
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i], tc = c + dc[i];

		if (Bamboo[tr][tc] > Bamboo[r][c]) //���ο� ���� �볪���� ������ ����
			dis[r][c] = max(dis[r][c], dfs({ tr, tc }));
	}

	dis[r][c]++;

	if (max_life < dis[r][c])
		max_life = dis[r][c];

	return dis[r][c];
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Bamboo[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dfs({ i,j });

	cout << max_life;
	return 0;
}
#pragma region first
//#include <iostream>
//#include <vector>
//#include <queue>
//#define MAX_SIZE 501
//using namespace std;
//int Bamboo[MAX_SIZE][MAX_SIZE];
//int dis[MAX_SIZE][MAX_SIZE];
//bool check[MAX_SIZE][MAX_SIZE];
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//int n, max_life;
//struct pii {
//	int r, c;
//};
//int bamb_max(int a, int b, int c, int d,int e) {
//	return max(max(max(max(a, b), c), d),e);
//}
//void print_map() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			cout<<dis[i][j] << " ";
//		cout << endl;
//	}
//}
//int dfs(pii node, int bamb) {//���ο� ��ǥ����, ���� �볪�� ��
//	int r = node.r;
//	int c = node.c;
//	if (r<0 || c<0 || r>n - 1 || c>n - 1)	return 0;
//	if (Bamboo[r][c] <= bamb) return 0;
//
//	if (dis[r][c] != 0) {
//		return dis[r][c];//+1?
//	}
//
//	
//	int up=dfs({ r - 1,c }, Bamboo[r][c]);
//	int down=dfs({ r + 1,c }, Bamboo[r][c]);
//
//	int left=dfs({ r,c - 1 }, Bamboo[r][c]);
//	int right=dfs({ r,c + 1 }, Bamboo[r][c]);
//
//
//	dis[r][c] = bamb_max(dis[r][c],up,down,left,right)+1;
//	if (max_life < dis[r][c]) max_life = dis[r][c];
//	// return  ���� dis + max(�����¿�);
//
//
//	return dis[r][c];
//}
//int main(void) {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> Bamboo[i][j];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			dfs({ i,j },Bamboo[i][j]);
//		}
//	}
//	cout << max_life;
//	return 0;
//}
#pragma endregion

