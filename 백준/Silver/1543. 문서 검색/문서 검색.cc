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

int main() {
	string s, sep;
	
	getline(cin, s);
	getline(cin, sep);
	int cnt = 0;
	int f = s.find(sep);
	while (f != -1) {
		cnt++;
		f = s.find(sep, f + sep.size());
	}
	cout << cnt;
}