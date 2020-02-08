#pragma region my_solve
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//string basic;
//string name;
//void print(vector<char> &str) {
//	reverse(str.begin(), str.end());
//	cout << basic;
//	for (int i = 0; i < str.size(); i++)
//		cout << str[i];
//	cout << " " << name << ";\n";
//}
//void input_name() {
//	vector<char> n;
//	char b;
//	while (b=getchar()) {
//		if (b != '&' && b != '*' && b != '[' && b != ']'&& b != ',' && b != ';')
//			name += b;
//		else {
//			cin.putback(b);
//			return;
//		}
//	}
//}
//int main(void) {
//	cin >> basic;
//	vector<char> str;
//	char a;
//	bool key = false;
//	while (a = getchar()) {
//		if (a == ' ') continue;
//		if (a != '&' && a != '*' && a != '[' && a != ']') {
//			if (a != ',' && a != ';') {
//				cin.putback(a);
//				input_name();
//				continue;
//			}
//		}
//		if (a != ',' && a != ';') {
//			if (a == '[') {
//				getchar();
//				str.push_back(']');	str.push_back('[');
//			}
//			else
//				str.push_back(a);
//			continue;
//		}
//		else if (a == ';') key=true;
//
//		print(str);
//		str.clear();
//		name.clear();
//		if (key) break;
//	}
//	
//	return 0;
//}
#pragma endregion

#pragma region refer
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	string type, vars;
	cin >> type;

	while (cin >> vars){
		string var, opt;
		for (char c : vars){
			if (c == ',' || c == ';'){
				cout << type << opt << " " << var << ";\n";
				break;
			}
			else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
				var += c;
			else if (c == '[')
				opt.insert(opt.begin(), ']');
			else if (c == ']')
				opt.insert(opt.begin(), '[');
			else
				opt.insert(opt.begin(), c);
		}
	}

	return 0;
}
#pragma endregion