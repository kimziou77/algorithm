#include <iostream>
#include <string>
#include <vector>
#include <deque>
/*
격자의 가장 아래 칸부터 차곡차곡 쌓여 있습니다. 게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을 집어 올릴 수 있습니다
같은 모양 인형 두 개가 없어집니다.


*/

using namespace std;
vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
vector<int> moves = { 1,5,3,5,1,2,1,4 };
int result = 0;
void print_deque() {
    cout << basket.size() << endl;
    for (auto i : basket) {
        cout << i << " ";
    }
    cout << endl << endl;

}
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    return answer;
}
void check(int o) {
    if (!basket.empty()) {
        if (basket.back() == o) {//들어온 인형이랑 맨 위가 같다면
            //print_deque();
            //cout << o << " 축하합니다 " << endl;
            basket.pop_back();//빼고
            result += 2;//결과추가

        }
        else {
            basket.push_back(o);
        }
    }
    else basket.push_back(o);
}
void print_map(){
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";
}

int main(void) {
    
    for (auto i : moves) {
        int down = 0, col = --i;
        while (down < board.size()-1 && board[down][col] == 0) down++;

        int doll = board[down][col];
        if (doll == 0) continue;
        board[down][col] = 0;
        check(doll);
        //print_map();

    }
    cout << result;

    return 0;
}