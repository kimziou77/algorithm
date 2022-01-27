#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int mini = 2000;
using pii = pair<int, int>;

vector<vector<int>> map;//����
vector<pii> chicken_house;//ġŲ����ǥ
vector<pii> nomal_house;//��������ǥ

int dis(pii a, pii b);
void city_chick_street(vector<bool>& check);

// �Ÿ��� ����ϴ� �Լ�
int dis(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void close_chicken(vector<bool> & check,int index,int num) {//�ش� �ε����� ������� ������
	if (num == M) {//M���� �����ߴٸ� return
		city_chick_street(check);
		return;
	}
	//������ üũ�ؼ� M�� ���� ���ҰͰ����� ���߱�
	//���� �� �����ؾ��� ���� < ������ ��� ���������� ����
	if (M - num > num + chicken_house.size() - index)
		return;

	if (index >= chicken_house.size())return;
	close_chicken(check,index + 1,num);//�ȳְ� ���
	check[index] = true;

	close_chicken(check,index + 1,num+1);//�ְ� ���
	check[index] = false;
}	

// ������ ġŲ�Ÿ� ���� �ּ��̸� ����
void city_chick_street(vector<bool> & check) {
	int tmp;
	int sum = 0;
	//������ ġŲ�Ÿ�
	for (auto i : nomal_house) {
		int street = 100;
		for (int j = 0; j < chicken_house.size(); j++) {
			if(check[j])
				street = min(dis(i, chicken_house[j]), street);
		}
		sum += street;
	}
	if (mini > sum)
		mini = sum;
}


int main(void) {
	cin >> N >> M;
	int cnt = 0;

	map.resize(N+1,vector<int>(N+1,0));

	for (int i = 1; i < N+1; i++)
		for (int j = 1; j < N + 1; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				chicken_house.push_back({ i, j });
			else if (map[i][j] == 1)
				nomal_house.push_back({ i,j });
		}

	vector<bool> check(chicken_house.size(), false);
	close_chicken(check,0,0);//M�� ���� ��� �ݱ�

	cout << mini;

	return 0;
}