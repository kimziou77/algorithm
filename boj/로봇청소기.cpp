#include <iostream>
#define MAX_SIZE 51
using namespace std;
using pii = pair<int, int>;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int num = 0;
int answer = 0;
//�� �� �� ��

int map[MAX_SIZE][MAX_SIZE];
void clean(int x, int y) {
	map[x][y] = 2;
	answer++;
}
int check_left(int x, int y) {
	if (map[x][y] == 0) {//û�� �ؾ��� ����
		return 1;
	}
	else if (map[x][y] == 1||map[x][y]==2) {//û�� �Ǿ��ְų� ���ΰ��
		return 2;
	}
}
pii back(int x,int y,int d) {
	int nx, ny;
	//���� �ٶ󺸰� �ִ� ������ �������� ���� ��ǥ�� �̵�
	if (d > 1) {
		nx = x + dx[d - 2];
		ny = y + dy[d - 2];
	}
	else {
		nx = x + dx[d + 2];
		ny = y + dy[d + 2];
	}
	if (map[nx][ny]!=1)//������ ���� �ƴ϶�� ��������
		return { nx,ny };
	return { -1,-1 };
}

void run(int r, int c, int d) {
	int x = r, y = c, nx, ny;

	if (map[x][y] == 0) {
		clean(x, y);//1 ���� ��ġ�� û���Ѵ�
		//cout << "(r,c) : " << r << "," << c << " �� û���մϴ�" << endl;
	}

	if (num == 4) {//2 c �׹��� ��� ���� �Ұ���
		num = 0;
		pii tmp = { -1,-1 };
		pii b = back(x, y, d);
		if (b != tmp) {//����
			return run(b.first, b.second, d);//(������ǥ, �������״��)
		}
		else {//2 d ���� �Ұ���
			return;//�۵�����
		}
	}

	//���ʹ���
	if (d > 0) {
		nx = x + dx[d - 1];
		ny = y + dy[d - 1];
	}
	else {
		nx = x + dx[3];
		ny = y + dy[3];
	}
	
	int cl = check_left(nx,ny);

	if (cl == 1) {//2 a ���ʿ� û������ ���� ����( 0�̸� )
		num = 0;
		if (d > 0)
			return run(nx, ny, d - 1);//ȸ���ϰ� �����ϰ� û��
		else
			return run(nx, ny, 3);
	}
	else if (cl == 2) {//2 b û���� ������ ���ٸ�(1 �̸�)
		num++;//ȸ��Ƚ��
		if (d > 0)
			return run(x, y, d - 1);//�������� ȸ����
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