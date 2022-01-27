#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<string> words;
bool comp(string a, string b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length()) {
		return a < b;
	}
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	words.resize(N);
	for (int i = 0; i < N; i++)
		cin >> words[i];
	sort(words.begin(), words.end(), comp);

	words.erase(unique(words.begin(), words.end()),words.end());
	for (auto i : words)
		cout << i << "\n";
	return 0;
}