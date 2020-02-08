#include <iostream>
#include <queue>
#define MAX_SIZE 2000
using namespace std;
int s;//이모티콘 s개 보내기
bool check[MAX_SIZE];
void bfs(int node) {
	/*
		배열에
		1. 화면에 있는 이모티콘 모두 복사해서 클립보드에 저장 (덮어쓰기됨)
		현재 디스플레이에 있는 이모티콘의 개수 clipBoard에 저장
		clipBoard = display+1;

		2. 클립보드에 있는 모든 이모티콘 화면에 붙여넣기
		(비어있을땐 붙여넣기 불가능)
		(붙여넣기 시에 이모티콘 개수도 화면에 추가됨)
		display.push(clipBoard);

		3. 화면에 있는 이모티콘 중 하나 삭제
		-1
	*/
	queue<int> q; q.push(node);	check[node] = true;

	int time = 0; //S개의 이모티콘을 만드는데 걸리는 시간의 최소값
	while (!q.empty()) {
		cout << "timeLine---------------------------" << endl;
		int size = q.size();
		for (int i = 0; i < size; i++) {

			int display = q.front(); q.pop();
			int clipBoard=display+1;

			if (display == s) {
				cout << time;
				return;
			}

			vector<int> make;
			make.push_back(0); make.push_back(-1);	make.push_back(clipBoard);
			cout << "clipBoard : " << clipBoard << endl;

			for (int i = 0; i < 3; i++) {
				if (display <= 0 && i == 0) continue;
				if (display > 1000 && i == 1) continue;
				int ns = display + make[i];
				if (ns>0&&!check[ns]) {// 기존에 만들지 못했던 개수의 스티커 개수라면
					cout << "ns : " << ns << endl;
					q.push(ns);
					check[ns] = true;
				}
				else {
					cout << ns << "is already exist!!" << endl;
				}
			}
		}
		time++;
	}

}
int main(void) {
	cin >> s;
	bfs(1);
	//output : 이모티콘 s개를 만들기 ㅜ이해 필요한 시간의 최소값
	return 0;
}