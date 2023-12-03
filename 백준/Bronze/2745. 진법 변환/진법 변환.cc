#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
vector<char> c;
int main() {
	
	int n = 0;
	string s;
	int b;
	cin >> s >> b;
	//b+1 A 
	//b+2 B
	//b+3 C..
	int sum = 0;
	int cnt = 0;
	for (int i = s.length() - 1;i>=0; i--) {
		int temp = s[i];

		if (s[i] >= 'A' && s[i] <= 'Z') {
			int num = s[i] - 'A'+10;
			//cout << num << endl;
			sum = sum + num*pow(b, cnt);
		}
		else {
			int num = s[i]-'0';
			sum = sum + num * pow(b, cnt);
		}
		cnt++;
		
	}
	cout << sum << "\n";
	
}