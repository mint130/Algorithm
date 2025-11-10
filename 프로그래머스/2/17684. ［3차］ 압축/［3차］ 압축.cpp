#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, int> m;
vector<int> solution(string msg) {
    vector<int> answer;
    for(int i=0;i<26;i++){
        char c = 'A'+i;
        string s="";
        s=c;
        m[s]=i+1;
    }
    for(int i=0;i<msg.length();){
        string tmp = msg.substr(i, 1); // i번째 1자리
        int j=i+1;
        for(;j<msg.length();j++){
            // i의 다음번째부터
        
            if(m[tmp+msg[j]]==0){
                // 없음
                m[tmp+msg[j]]=m.size(); // 추가
                break;
            }
            tmp+=msg[j]; // 부분 문자열 늘려감
        }
        //cout<<tmp<<endl;
        answer.push_back(m[tmp]);
        i=j;
    }
    return answer;
    
}