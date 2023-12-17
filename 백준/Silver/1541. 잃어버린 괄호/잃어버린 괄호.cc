#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	string s;
	cin >> s;
	
	
	int answer = 0;
	bool minus = false;
	

	string num = ""; 
	for (int i = 0; i <=s.length(); i++) {
		//음수를 만나면 다시 음수를 만나기 전 까지 숫자를 빼주면 된다
		if (s[i] == '+'||s[i]=='-'||i==s.length()) {
			if (minus == true) {
				answer = answer - stoi(num);
				num = "";
				
			}
			else {
				answer = answer + stoi(num);
				num = "";
			}
			
		}
		else {
			num += s[i];
		}
		if (s[i] == '-') {
			
			minus = true;
		}

		


	}
	cout << answer;
}