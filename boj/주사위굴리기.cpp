#include <iostream>
#define MAX_SIZE 21

#define EAST 1 //��
#define WEST 2 //��
#define SOUTH 3 //��
#define NORTH 4 //��
using namespace std;

int dc[] = { 0,1,-1,0,0 };//x
int dr[] = { 0,0,0,-1,1 };//y

int map[MAX_SIZE][MAX_SIZE];
int dice[4][3] = { 0, };
int N, M, K;
int x, y;

bool check_map(int r, int c) {
	return r<0 || r>N - 1 || c<0 || c>M - 1;
}

void copy(int r, int c) {
	if (map[r][c] == 0) {
		map[r][c] = dice[3][1];//�ֻ����� �ٴڸ��� �ʿ� ����
	}
	else {
		dice[3][1] = map[r][c];//���� ���� �ֻ��� �ٴڿ� ����
		map[r][c] = 0;//���� 0
	}
}

void run(int dir) {
	switch (dir) {
	case EAST: {//��
		int tmp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = tmp;
		break;
	}
	case WEST: {//��
		int tmp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = tmp;
		break;
	}
	case SOUTH: {//��
		int tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = tmp;
		break;
	}
	case NORTH: {//��
		int tmp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = tmp;
		break;
	}
	}

}

int main(void) {
	cin >> N >> M >> y >> x >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++) {
		int dir;	cin >> dir;
		int nr = y + dr[dir];
		int nc = x + dc[dir];
		if (!check_map(nr, nc)) continue;
		y = nr; x = nc;
		run(dir);
		copy(nr, nc);
		cout << dice[1][1] << endl;
	}
	return 0;
}