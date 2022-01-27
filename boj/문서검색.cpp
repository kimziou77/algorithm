#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> makeTable(string p) {
	int m = p.size();
	vector<int> table(m, 0);
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = table[j - 1];

		if (p[i] == p[j])
			table[i] = ++j;
	}
	return table;
}

int kmp(string s, string p) {
	auto table = makeTable(p);
	int parentSize = s.size();
	int patternSize = p.size();
	table[patternSize - 1] = 0;//¹®ÀÚ¿­À» ¹ß°ßÇß´Ù¸é ´Ù½Ã 0À¸·Î µ¹¾Æ°¡¾ß ÇÏ¹Ç·Î

	int j = 0;//ÀÎµ¦½º´Â 0ºÎÅÍ ½ÃÀÛ
	int answer = 0;
	for (int i = 0; i < parentSize; i++) {//¹®ÀÚ¿­ Ã³À½ºÎÅÍ Å½»öÇÏ´Âµ¥

		while (j > 0 && s[i] != p[j]) //j¹ø¤Š¶û ºñ±³
			j = table[j - 1];//j°ªÀ» °è¼Ó À¯µ¿ÀûÀ¸·Î º¯°æ½ÃÅ²´Ù.

		if (s[i] == p[j]) {
			if (j == patternSize - 1) { //¸ðµÎ ¸Â­Ÿ´Ù¸é
				//cout << "Ã£Àº À§Ä¡ : " << i - petternSize + 1 << endl;
				j = 0;//´Ù½Ã °Ë»ç½ÃÀÛ
				answer++; // Á¤´ä°³¼ö ++
			}
			else {
				j++;
			}
		}
	}
	return answer;
}
int main(void) {
	string a; string b;
	getline(cin,a);
	getline(cin,b);

	cout<<kmp(a, b);
	
	return 0;
}