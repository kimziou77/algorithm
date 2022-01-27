#include <iostream>
#define MAX_SIZE 51
using namespace std;
using pii = pair<int, int>;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int num = 0;
int answer = 0;
//북 동 남 서

int map[MAX_SIZE][MAX_SIZE];
void clean(int x, int y) {
	map[x][y] = 2;
	answer++;
}
int check_left(int x, int y) {
	if (map[x][y] == 0) {//청소 해야할 공간
		return 1;
	}
	else if (map[x][y] == 1||map[x][y]==2) {//청소 되어있거나 벽인경우
		return 2;
	}
}
pii back(int x,int y,int d) {
	int nx, ny;
	//현재 바라보고 있는 방향을 기준으로 뒤쪽 좌표로 이동
	if (d > 1) {
		nx = x + dx[d - 2];
		ny = y + dy[d - 2];
	}
	else {
		nx = x + dx[d + 2];
		ny = y + dy[d + 2];
	}
	if (map[nx][ny]!=1)//뒤쪽이 벽이 아니라면 후진가능
		return { nx,ny };
	return { -1,-1 };
}

void run(int r, int c, int d) {
	int x = r, y = c, nx, ny;

	if (map[x][y] == 0) {
		clean(x, y);//1 현재 위치를 청소한다
		//cout << "(r,c) : " << r << "," << c << " 를 청소합니다" << endl;
	}

	if (num == 4) {//2 c 네방향 모두 전진 불가능
		num = 0;
		pii tmp = { -1,-1 };
		pii b = back(x, y, d);
		if (b != tmp) {//후진
			return run(b.first, b.second, d);//(후진좌표, 방향은그대로)
		}
		else {//2 d 후진 불가능
			return;//작동정지
		}
	}

	//왼쪽방향
	if (d > 0) {
		nx = x + dx[d - 1];
		ny = y + dy[d - 1];
	}
	else {
		nx = x + dx[3];
		ny = y + dy[3];
	}
	
	int cl = check_left(nx,ny);

	if (cl == 1) {//2 a 왼쪽에 청소하지 않은 공간( 0이면 )
		num = 0;
		if (d > 0)
			return run(nx, ny, d - 1);//회전하고 전진하고 청소
		else
			return run(nx, ny, 3);
	}
	else if (cl == 2) {//2 b 청소할 공간이 없다면(1 이면)
		num++;//회전횟수
		if (d > 0)
			return run(x, y, d - 1);//왼쪽으로 회전만
		else
			return run(x, y, 3);
	}
}
int main(void) {
	int n, m;	cin >> n >> m;
	int r, c, d;	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	run(r, c, d);

	cout << answer;
	return 0;
}