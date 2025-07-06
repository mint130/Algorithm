#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool check(string s){
    //올바른 괄호 문자열인지 체크
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else {
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                if(st.top()=='(' || st.top()=='[' || st.top()=='{'){
                    st.push(s[i]);
                }
                else {
                    return false;
                }
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.top()=='{'){
                    if(s[i]!='}') return false;
                    else st.pop();
                }
                else if(st.top()=='('){
                    if(s[i]!=')') return false;
                    else st.pop();
                }
                else if(st.top()=='['){
                    if(s[i]!=']') return false;
                    else st.pop();
                }
            }
            
        }
    }
    if(st.empty()) return true;
    else return false;
    
}
string left(string s, int num) {
    if(num==0) return s;
    queue<char> q;
    for(int i=0;i<s.length();i++){
        q.push(s[i]);
    }
    for(int i=1;i<=num;i++){
        char c = q.front();
        q.pop();
        q.push(c);
    }
    string str="";
    while(!q.empty()){
        str+=q.front();
        q.pop();
    }
    return str;
}
int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.length();i++){
        //왼쪽으로 한칸씩 이동
        if(check(left(s, i))){
            answer++;   
        }
    }
    return answer;
}