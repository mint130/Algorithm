#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n), nxt(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        prev[i]=i-1;
        nxt[i]=i+1;
    }
    nxt[n-1]=-1;
    int cur = k;
    for(string s:cmd){
        char c= s[0];
        if(c=='U'){
            int x = stoi(s.substr(2));
            while(x--){
                cur = prev[cur];
            }
        }
        else if(c=='D'){
            int x = stoi(s.substr(2));
            while(x--){
                cur = nxt[cur];
            }
        }
        else if(c=='C'){
            st.push(cur);
            
            if(prev[cur]!=-1){
                nxt[prev[cur]]=nxt[cur];
            }
            if(nxt[cur]!=-1){
                prev[nxt[cur]]=prev[cur];
            }
            if(nxt[cur]==-1){
                cur = prev[cur];
            }
            else cur = nxt[cur];
        }
        else if(c=='Z'){
            int num = st.top(); st.pop();
            
            if(prev[num]!=-1) nxt[prev[num]]=num;
            if(nxt[num]!=-1) prev[nxt[num]]=num;
        }
    }
    string answer(n, 'O');
    while(!st.empty()){
        answer[st.top()]='X';
        st.pop();
    }
    return answer;
}