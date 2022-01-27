#include <iostream>
#include <queue>
#define MAX_SIZE 2000
using namespace std;
int s;//�̸�Ƽ�� s�� ������
bool check[MAX_SIZE];
void bfs(int node) {
	/*
		�迭��
		1. ȭ�鿡 �ִ� �̸�Ƽ�� ��� �����ؼ� Ŭ�����忡 ���� (������)
		���� ���÷��̿� �ִ� �̸�Ƽ���� ���� clipBoard�� ����
		clipBoard = display+1;

		2. Ŭ�����忡 �ִ� ��� �̸�Ƽ�� ȭ�鿡 �ٿ��ֱ�
		(��������� �ٿ��ֱ� �Ұ���)
		(�ٿ��ֱ� �ÿ� �̸�Ƽ�� ������ ȭ�鿡 �߰���)
		display.push(clipBoard);

		3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ� ����
		-1
	*/
	queue<int> q; q.push(node);	check[node] = true;

	int time = 0; //S���� �̸�Ƽ���� ����µ� �ɸ��� �ð��� �ּҰ�
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
				if (ns>0&&!check[ns]) {// ������ ������ ���ߴ� ������ ��ƼĿ �������
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
	//output : �̸�Ƽ�� s���� ����� ������ �ʿ��� �ð��� �ּҰ�
	return 0;
}