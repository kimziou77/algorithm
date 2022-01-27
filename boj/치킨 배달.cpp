#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int mini = 2000;
using pii = pair<int, int>;

vector<vector<int>> map;//도시
vector<pii> chicken_house;//치킨집좌표
vector<pii> nomal_house;//가정집좌표

int dis(pii a, pii b);
void city_chick_street(vector<bool>& check);

// 거리를 계산하는 함수
int dis(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void close_chicken(vector<bool> & check,int index,int num) {//해당 인덱스를 사용할지 안할지
	if (num == M) {//M개를 선택했다면 return
		city_chick_street(check);
		return;
	}
	//사이즈 체크해서 M개 선택 못할것같으면 멈추기
	//현재 더 선택해야할 개수 < 남은거 모두 선택했을때 개수
	if (M - num > num + chicken_house.size() - index)
		return;

	if (index >= chicken_house.size())return;
	close_chicken(check,index + 1,num);//안넣고 재귀
	check[index] = true;

	close_chicken(check,index + 1,num+1);//넣고 재귀
	check[index] = false;
}	

// 도시의 치킨거리 합이 최소이면 갱신
void city_chick_street(vector<bool> & check) {
	int tmp;
	int sum = 0;
	//도시의 치킨거리
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
	close_chicken(check,0,0);//M개 빼고 모두 닫기

	cout << mini;

	return 0;
}