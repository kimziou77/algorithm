#include <iostream>
#include <queue>
using namespace std;

bool apple[101][101];//사과의 위치
bool check[101][101];//현재 뱀의 위치
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int N, K, d, result;

struct pii {
	//좌표가 100이상으로 커지지 않으므로 char사용
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
	pii& head = snake.body.back();//머리
	pii& tail = snake.body.front();//꼬리

	check[head.r][head.c] = true;

	//이동하기
	if (snake.dir < 0) snake.dir += 4;
	else snake.dir %= 4;
	char nr = head.r + dr[snake.dir];
	char nc = head.c + dc[snake.dir];

	if (nr < 1 || nc < 1 || nr>N || nc>N)//벽과 충돌
		return snake.t;

	if (check[nr][nc]) //자기 몸통이랑 충돌
		return snake.t;

	check[nr][nc] = true;//한칸 이동

	if (apple[nr][nc]) {//사과가 있다면
		apple[nr][nc] = false;//사과를 먹고 
		check[nr][nc] = true;//몸통길이를 늘린다.
	}
	else {//사과가 없다면
		check[tail.r][tail.c] = false;//꼬리 이동
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

	cin >> d;// 뱀의 방향 변환 횟수 d

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