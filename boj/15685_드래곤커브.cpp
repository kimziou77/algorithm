#include <iostream>
#include <vector>
#define MAX_SIZE 101
using namespace std;
int N;
bool map[MAX_SIZE][MAX_SIZE];
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
int check_map() {
	int num = 0;
	for (int i = 0; i < MAX_SIZE - 1; i++)
		for (int j = 0; j < MAX_SIZE - 1; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				num++;
	return num;
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> curves;
		int x, y;//���� ��
		int d, g;//���� ���� , ����
		cin >> x >> y >> d >> g;
		curves.push_back(d);
		for (int j = 0; j < g; j++) {
			for (int k = curves.size() - 1; k >= 0; k--) {//�Ųٷ� ��ȸ�ϸ鼭 ���븦 ����� ����.
				curves.push_back((curves[k] + 1) % 4);
			}
		}
		map[y][x] = 1;
		for (int dir : curves) {
			x += dx[dir];
			y += dy[dir];
			if (x < 0 || y < 0 || x>100 || y>100) continue;
			map[y][x] = 1;
		}
		//map[y][x]���� �����ؼ�
		//���۹������� curve�� ����� ������.
	}
	cout << check_map();

	return 0;
}
