#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <iostream>
#include <iostream>
using namespace std;
int answer = 0;
int len = 0;

bool isright(string s){
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            if(s[i]=='}' || s[i]==')' || s[i]==']') return false;
            st.push(s[i]);
        }
        else {
            char c = st.top();
            //cout<<c<<endl;
            // 닫힌 괄호면 return false
            if(c=='}' || c==')' || c==']') return false;
            // 열린 괄호면
            if(c=='(') {
                if(s[i]==')') st.pop();
                else {
                    if(s[i]=='{' || s[i]=='[' || s[i]=='(') st.push(s[i]);
                    else return false;
                }
            }
            else if(c=='[') {
                if(s[i]==']') st.pop();
                else {
                    if(s[i]=='{' || s[i]=='[' || s[i]=='(') st.push(s[i]);
                    else return false;
                }
                
            }
            else if(c=='{'){
                if(s[i]=='}') st.pop();
                else {
                    if(s[i]=='{' || s[i]=='[' || s[i]=='(') st.push(s[i]);
                    else return false;
                }
            }
            // else if(s[i]=='}' && s[i]=='{') st.pop();
            // else if(s[i]==']' && s[i]=='[') st.pop();
            
        }
    }
    if(st.empty()) return true;
    else return false;
}
int solution(string s) {
    len = s.length();
    for(int i=0;i<len;i++){
        string str = s.substr(0, 1);
        s = s.substr(1, len-1)+str;
        if(isright(s)) answer++;
    }
    return answer;
}