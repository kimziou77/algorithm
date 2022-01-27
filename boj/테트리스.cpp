#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> block[7] = {
   {
	  {0},{0, 0, 0, 0}//1
   },
   {
	  {0, 0}//2
   },
   {
	  {0, 0, 1},{0, -1}//3
   },
   {
	  {0, -1, -1},{0, 1}//4
   },
   {
	  {0, 0, 0},{0, 1},{0, -1, 0},{0, -1}//5
   },
   {
	  {0, 0, 0},{0, 0},{0, 1, 1},{0, -2}//6
   },
   {
	  {0, 0, 0},{0, 2},{0, 0, -1},{0, 0}//7
   }
};

int main(void) {
	int C, P;	cin >> C >> P;	P--;
	vector<int> map(C,0);
	for (int i = 0; i < C; i++)
		cin >> map[i];
	int answer = 0;

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < block[P].size(); j++) {
			int size = 0;
			for (int k = 0; i + k < C && k < block[P][j].size(); k++) {
				if (map[i + k] != map[i] + block[P][j][k])
					break;
				size++;
			}
			if (size == block[P][j].size())	answer++;
		}
	}
	cout << answer;
	return 0;
}