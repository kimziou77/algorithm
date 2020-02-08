#pragma region combination
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//
//template<typename Container_, typename value_type = Container_::value_type>
//vector<vector<value_type> > Combination(Container_ container, int r) {
//	int n = container.size();
//	if (n < r) return {};
//	if (r < 0) return {};
//
//	vector<vector<value_type> >totVec;//return 2d-vector
//	vector<value_type> tempVec(r);//saves temporary combination
//
//	vector<bool> v(n);
//	fill(v.end() - r, v.end(), true);
//	int idx;
//	do {
//		idx = 0;
//		for (int i = 0; i < n; ++i) {
//			if (v[i]) {
//				tempVec[idx++] = *(container.begin() + i);
//			}
//		}
//		totVec.push_back(tempVec);
//	} while (next_permutation(v.begin(), v.end()));
//
//	return totVec;
//}
//
//int main() {
//	vector<int> intVec{ 3, 2, 5, 1, 5 };
//	vector<string> strVec{ "Apple", "Banana", "Car" };
//
//	//intVec에 대해 3C2 수행
//	for (auto& vec : Combination(intVec, 2)) {
//		for (auto& ele : vec)
//			std::cout << ele << ' ';
//		cout << endl;
//	}
//	cout << endl;
//
//	//strVec에 대해 3C2 수행
//	for (auto& vec : Combination(strVec, 2)) {
//		for (auto& ele : vec)
//			cout << ele << ' ';
//		cout << endl;
//	}
//}
#pragma endregion

#pragma region permutation
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <cstdio>
//using namespace std;
//bool attendance(vector<char> v) {
//	for (int i = 0; i < v.size(); i++) {
//		int num = 0;
//		if (v[i] == 'B')
//			if (i + 1 < v.size() && v[i + 1] == 'B') return false;
//
//		if (v[i] == 'C') {
//			if (i+1<v.size()&&v[i + 1] == 'C') return false;
//			if (i + 2 < v.size() && v[i + 2] == 'C')return false;
//		}
//	}
//	return true;
//}
//
//int main(void) {
//	vector<char> v;		char a;
//
//	while (scanf("%1c", &a) && a != '\n')
//		v.push_back(a);
//	sort(v.begin(), v.end());
//
//	do {
//		for (int i = 0; i < v.size(); i++)
//			printf("%c", v[i]);
//		/*if (attendance(v)) {
//			for (int i = 0; i < v.size(); i++)
//				printf("%c", v[i]);
//			return 0;
//		}*/
//	} while (next_permutation(v.begin(), v.end()));
//	cout << -1;
//
//	return 0;
//}
#pragma endregion 


//순열 생성에 조건이 들어가있음
//내가직접 만들어줘야하려낭
//순열에는 순서가 있다 나온거 다시 나와도 됨.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> v;	char a;
vector<bool> check;

void dfs(int num, vector<char> p, int b, int c) {
	if (b == 2) b = 0;
	if (c == 3) c = 0;
	if (p.size() == v.size()) {//모두 선택했다면
		for (int i = 0; i < p.size(); i++)
			cout << p[i];
		cout << endl;
	}
	for (int i = 0; i < v.size(); i++) {
		check[i] = true;
		if (v[i] == 'B') {
			if (b++ == 1) continue;
		}
		if (v[i] == 'C') {
			if (c==1||c++ == 2) continue;
		}
		p.push_back(v[i]);
		dfs(i + 1, {},b,c);
		p.pop_back();
		if (v[i] == 'B') b--;
		if (v[i] == 'C')  c--;

		check[i] = false;
	}
}
int main(void) {
	while (scanf("%1c", &a) && a != '\n')
		v.push_back(a);
	sort(v.begin(), v.end());
	check.resize(v.size());
	dfs(0, {},0,0);

	return 0;
}