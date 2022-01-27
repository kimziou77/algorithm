#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int check[28];
int main(void) {
	int num = 0;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		check[a[i]-'a']++;
	for (int i = 0; i < b.size(); i++)
		check[b[i] - 'a']--;

	for (int i = 0; i <28; i++) {
		if (check[i] != 0)
			num += abs(check[i]);
	}
	cout << num;
	return 0;
}