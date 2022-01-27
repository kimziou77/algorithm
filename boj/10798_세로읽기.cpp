#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
	vector<string> str(5);
	for (int i = 0; i < 5; i++)
		cin >> str[i];
	int m = 0;
	for (auto i : str)
		if (m < i.size()) m = i.size();

	for (int o = 0; o < m; o++) {
		for (int word = 0; word < 5; word++) {
			if (str[word].size() <= o) continue;
			cout << str[word][o];
		}
	}
	return 0;
}