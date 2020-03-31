#include <iostream>
#include <vector>
using namespace std;
enum { LEFT, RIGHT };
int num;
int main(void) {
	vector<int> cows(11,-1);
	int N;	cin >> N;
	for (int i = 0; i < N; i++) {
		int cow, pos;	cin >> cow >> pos;
		if (cows[cow] == pos) continue;//if the position has already same position -> continues;
		switch (pos) {
		case LEFT:
			if (cows[cow] == RIGHT)	num++;
			cows[cow] = LEFT;
			break;
		case RIGHT:
			if (cows[cow] == LEFT) 	num++;
			cows[cow] = RIGHT;
			break;
		}
	}
	cout << num;

	return 0;
}