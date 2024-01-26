#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
bool cmp(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else if (a.size() == b.size()) {
		int asum = 0;
		int bsum = 0;
		for (int i = 0; i < a.size(); i++) {
			if (isdigit(a[i])) {
				asum += a[i]-'0';
			}
			if (isdigit(b[i])) {
				bsum += b[i]-'0';
			}
		}
		if (asum != bsum) return asum < bsum;
		else if (asum == bsum) {
			return a < b;
		}


	}

}

vector<string> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//A와 B의 길이가 다르면 짧은 것이 먼저 옴
	//서로 길이가 같다면 A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저 옴(숫자)
	//사전 순(숫자가 알파벳보다 작음)

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}