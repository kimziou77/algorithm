#include <iostream>
#include <vector>
#include <cstring>
#define MAX_SIZE 101
using namespace std;
int A, B, N, M;
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
// N E S W //
int map[MAX_SIZE][MAX_SIZE];

struct robot {
	int r, c, dir, num;
	robot(int _r, int _c, int _num, char d) : r(_r), c(_c), num(_num) {
		switch (d) {
		case 'N':
			dir = 0;
			break;
		case 'E':
			dir = 1;
			break;
		case 'S':
			dir = 2;
			break;
		case 'W':
			dir = 3;
			break;
		default:
			dir = 0;
		}
	}

	bool move(char order) {
		if (order == 'L') {
			if (--dir < 0) dir += 4;
			return false;
		}
		if (order == 'R') {
			if (++dir > 3) dir -= 4;
			return false;
		}
		//F
		map[r][c] = 0;//�̵��� �����Ƿ� �ٽ� 0 �ʱ�ȭ

		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (nr<1 || nc<1 || nr>B || nc>A) {//���� �ε����ٸ�
			cout << "Robot " << num << " crashes into the wall";
			return true;
		}
		if (map[nr][nc] != 0) {//�ٸ� �κ��� �ε����ٸ�
			cout << "Robot " << num << " crashes into " << "robot " << map[nr][nc];
			return true;
		}
		map[nr][nc] = num;//nr, nc �ڸ����� num�� �κ��� ����.
		r = nr;	c = nc;
		return false;
	}
};
vector<robot> v;
int main(void) {
	cin >> A >> B >> N >> M;
	//B�� ���� A�� ����
	v.push_back({ 0,0,0,0 });//0�� �κ��� ����.
	for (int i = 1; i <= N; i++) {//�κ� N��
		int x, y; char dir;//�ʱ���ġ�� ����
		cin >> x >> y >> dir;
		map[y][x] = i;
		v.push_back({ y,x,i,dir });
	}

	for (int j = 0; j < M; j++) {//��� M��
		int sel, trial; char order;
		cin >> sel >> order >> trial;
		while (trial--) {
			if (v[sel].move(order))
				return 0;
		}
	}
	cout << "OK";
	return 0;
}

/*
5 4
3 5
1 1 E
5 4 W
2 3 N
1 F 2
1 R 2
1 F 2
1 L 2
1 F 2

*/