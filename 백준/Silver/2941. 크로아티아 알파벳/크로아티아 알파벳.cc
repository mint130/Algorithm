#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;
vector<string> alphas = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" }; //크로아티아 문자를 치환
int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (auto alpha : alphas) {
		while (1) {
			int pos = str.find(alpha);
			if (pos == -1) break;
			str.replace(pos, alpha.size(), "1");
		}
	}
	cout << str.size();
	//크로아티아 문자가 있으면 1로 치환
}