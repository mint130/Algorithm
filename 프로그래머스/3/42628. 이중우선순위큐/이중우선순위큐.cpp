#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
deque<int> dq;
vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    for(int i=0;i<operations.size();i++){
        string s=operations[i];
        if(s[0]=='I'){
            //s[2]부터 마지막까지
            string num="";
            for(int j=2;j<s.length();j++){
                num+=s[j];
            }
            dq.push_back(stoi(num));
            sort(dq.begin(), dq.end());
            
        }
        
        if(s[0]=='D'){
            
            if(s[2]=='-'){
                //최소값 삭제
                if(!dq.empty()){
                    dq.pop_front();
                }
            }
            else {
                //최대값 삭제
                if(!dq.empty()){
                    dq.pop_back();
                }
                
            }
        }
    }
    if(dq.empty()){
        answer[0]=0; answer[1]=0;
    }
    else{
        if(dq.size()==1){
            answer[0]=dq[0];
            answer[1]=answer[0];
        }
        else {
            answer[1]=dq[0];
            answer[0]=dq[dq.size()-1];
        }
    }
    return answer;
}