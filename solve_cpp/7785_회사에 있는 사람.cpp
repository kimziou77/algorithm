#include <iostream>
#include <string>
#include <set>
#include <functional>
using namespace std;
int main(void) {
	int n;	cin >> n;
	set<string, greater<string>> s;

	for (int i = 0; i < n; i++) {
		string name, io;
		cin >> name >> io;
		if (io == "enter") s.insert(name);
		else
			s.erase(s.find(name));
	}
	for (auto i : s)
		cout << i << "\n";
	return 0;
}
