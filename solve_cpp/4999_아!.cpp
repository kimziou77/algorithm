#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string ze, doc;
	cin >> ze >> doc;
	if (ze.size() >= doc.size()) cout << "go";
	else cout << "no";
	return 0;
}