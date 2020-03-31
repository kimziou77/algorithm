#include <iostream>
#include <vector>
using namespace std;
struct Medal {
	int g=0, s=0, b=0;
	bool operator> (Medal& m) {
		if (g > m.g) return true;
		else if (g == m.g) {
			if (s > m.s) return true;
			else if (s == m.s) {
				if (b > m.b) return true;
				else return false;
			}
		}
		return false;
	}
};
struct Country {
	Medal m;
	int rank=0;
};
int set_rank(vector<Country>& v, int idx) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i].m > v[idx].m) cnt++;

	v[idx].rank = cnt + 1;
	return cnt + 1;
}
int main(void) {
	int N, K;	cin >> N >> K;
	vector<Country> v(N);
	for (int i = 0; i < N; i++) {
		int c, g, s, b;
		cin >> c >> g >> s >> b;
		v[c-1] = { g,s,b };
	}
	cout<< set_rank(v, K-1);
	return 0;
}

//for (auto i : v) {
//	cout << i.rank << " ";
//}
//cout << endl;
