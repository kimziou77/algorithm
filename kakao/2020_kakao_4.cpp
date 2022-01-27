/*

�����Ÿ��� ȣ���� ��ϰ� �ִ� ��ī�Ǵ� ȣ�ڿ� �����Ϸ��� ���鿡�� ���� �����Ϸ� �մϴ�. ȣ�ڿ��� ���� �� k�� ������,
������ ���� 1������ k������ ��ȣ�� �����ϰ� �ֽ��ϴ�. ó������ ��� ���� ��� ������ ��ī�Ǵ� ������ ���� ��Ģ�� ���� ������ ���� �����Ϸ��� �մϴ�.

�� ���� �� �� ��û�� ������� ���� �����մϴ�.
���� �����ϱ� ���ϴ� �� ��ȣ�� �����մϴ�.
���� ���ϴ� ���� ��� �ִٸ� ��� �����մϴ�.
���� ���ϴ� ���� �̹� �����Ǿ� ������ ���ϴ� �溸�� ��ȣ�� ũ�鼭 ����ִ� �� �� ���� ��ȣ�� ���� ���� �����մϴ�.
���� ���, ���� �� 10���̰�, ������ ���ϴ� �� ��ȣ�� ������� [1, 3, 4, 1, 3, 1] �� ��� ������ ���� ���� �����ް� �˴ϴ�.
���ϴ� �� ��ȣ	������ �� ��ȣ
1	1
3	3
4	4
1	2
3	5
1	6

��ü �� ���� k�� ������ ���ϴ� �� ��ȣ�� ������� ����ִ� �迭 room_number�� �Ű������� �־��� ��,
�� ������ �����Ǵ� �� ��ȣ�� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

*/
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <iterator>

using namespace std;
set<long long> s;
vector<long long> answer;

void find_empty_room(long long i) {
    //empty�� ������
    auto empty = s.upper_bound(i);//���� �� ��ȣ���� ū ����������
    if (empty==s.end()) {
        answer.push_back(*s.rbegin() +1);
        s.insert(*s.rbegin() + 1);
        return;
    }
    if (*empty-i > 1) {//�߰��� �� ���� ����
        answer.push_back(i + 1);//�ٷ� ��ĭ�� �ش�.
        s.insert(i + 1);
        return;
    }
    else if (*empty -i > 0) {//�ٷ� ��ĭ�ڿ� �Ǵٽ� ����� �ִٸ�
        return find_empty_room(*empty);    //empty�� �ٽ� ū��ã��
    }

}

vector<long long> solution(long long k, vector<long long> room_number) {

    for (auto i : room_number) {
        auto p = s.insert(i);
        if (p.second) {//����̾��ٸ�
            answer.push_back(i);
        }
        else {//����̾ƴϾ��ٸ�
            find_empty_room(i);//p.first���� ū �� Ž��
        }
    }
    cout << endl;
    return answer;
}
int main(void) {
    long long k = 10;
    vector<long long> room_number = { 1,3,4,1,3,1 };
    auto result = solution(k, room_number);
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}