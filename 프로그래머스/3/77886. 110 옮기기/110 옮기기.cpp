#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(int i=0;i<s.size();i++){
        string str = s[i];
        stack<char> st;
        int cnt = 0; // 110 갯수
        for(int j=0;j<str.length();j++){
            st.push(str[j]);
            if(st.size()>=3){
                char a = st.top(); st.pop();
                char b = st.top(); st.pop();
                char c = st.top(); st.pop();
                if(a=='0' && b=='1' && c=='1'){
                    // 110 만들어짐
                    cnt++; //갯수 증가
                }
                else {
                    st.push(c); st.push(b); st.push(a); // 다시 넣음
                }
            }
        }
        // stack에 110을 뺀 문자열 들어있음
        string res = "";
        while(!st.empty()){
            res +=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end()); // res에 110을 뺸 문자열
        
        int idx = -1; // 가장 마지막으로 나오는 0의 위치
        for(int j=res.length()-1;j>=0;j--){
            if(res[j]=='0'){
                idx = j;
                break;
            }
        }
        while(cnt--){
            // 110의 갯수만큼 반복
            res.insert(idx+1, "110");
            idx +=3;
        }
        answer.push_back(res);
    }
    return answer;
}