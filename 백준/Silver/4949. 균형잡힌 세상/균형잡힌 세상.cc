#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	
	while (1) {
		getline(cin, s);
		if (s[0] == '.') return 0;
		else {
		
			//.으로 구분하여 문장 받음
			stack<char> st;
			int flag = 0; //valid
			for (int i = 0; i < s.length(); i++) {

				if (s[i] == '[' || s[i] == '(') {
					st.push(s[i]);
					//여는 괄호일 때 스택에 push
				}
				else if (s[i] == ')') {
					if (st.empty() || st.top() != '(') {
						//스택이 비어있거나 top의 괄호쌍이 다르면 잘못 들어온 괄호이므로 no 출력, break
						//cout << "no" << "\n";
						flag = 1;
						break;
					}
					if (st.top() == '(') {
						//짝이 맞으므로 pop
						st.pop();
					}
				}
				else if (s[i] == ']') {
					if (st.empty() || st.top() != '[') {
						//스택이 비어있거나 top의 괄호쌍이 다르면 잘못 들어온 괄호이므로 no 출력, break
						//cout << "no" << "\n";
						flag = 1;
						break;
					}
					if (st.top() == '[') {
						//짝이 맞으므로 pop
						st.pop();
					}

				}
			}
			if (!st.empty()) flag = 1;
			if (!flag) cout << "yes\n";
			else cout << "no\n";
			
		}
		
	}
	
}