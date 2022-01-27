#include <iostream>
#include <queue>
using namespace std;

bool apple[101][101];//����� ��ġ
bool check[101][101];//���� ���� ��ġ
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int N, K, d, result;

struct pii {
	//��ǥ�� 100�̻����� Ŀ���� �����Ƿ� char���
	char r, c;
};
struct Snake {
	char dir;
	deque<pii> body;
	int t;
};
Snake snake{ 2,{},0 };
int game_start() {

	snake.t++;
	pii& head = snake.body.back();//�Ӹ�
	pii& tail = snake.body.front();//����

	check[head.r][head.c] = true;

	//�̵��ϱ�
	if (snake.dir < 0) snake.dir += 4;
	else snake.dir %= 4;
	char nr = head.r + dr[snake.dir];
	char nc = head.c + dc[snake.dir];

	if (nr < 1 || nc < 1 || nr>N || nc>N)//���� �浹
		return snake.t;

	if (check[nr][nc]) //�ڱ� �����̶� �浹
		return snake.t;

	check[nr][nc] = true;//��ĭ �̵�

	if (apple[nr][nc]) {//����� �ִٸ�
		apple[nr][nc] = false;//����� �԰� 
		check[nr][nc] = true;//������̸� �ø���.
	}
	else {//����� ���ٸ�
		check[tail.r][tail.c] = false;//���� �̵�
		snake.body.pop_front();
	}

	snake.body.push_back({ nr,nc });
	return -1;
}
int main(void) {
	snake.body.push_back({ 1,1 });
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;	cin >> a >> b;
		apple[a][b] = 1;
	}

	cin >> d;// ���� ���� ��ȯ Ƚ�� d

	for (int i = 0; i < d; i++) {
		int t;	char dir;
		cin >> t >> dir;
		while (true) {
			if (snake.t == t && dir == 'L') snake.dir--;
			if (snake.t == t && dir == 'D') snake.dir++;
			result = game_start();

			if (result != -1) {
				cout << result;
				return 0;
			}

			if (snake.t > t) break;
		}
	}
	while (result == -1) {
		result = game_start();
	}
	cout << result;

	return 0;
}