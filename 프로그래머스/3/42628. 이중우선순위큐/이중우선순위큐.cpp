#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
multiset<int> ms;
vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    for(int i=0;i<operations.size();i++){
        string s=operations[i];
        if(s[0]=='I'){
            string str="";
            for(int j=2;j<s.length();j++){
                str+=s[j];
            }
            ms.insert(stoi(str));
        }
        else {
            if(s[2]=='-'){
                //최소값 삭제
                if(!ms.empty()){
                    ms.erase(ms.begin());
                }
            }
            else{
                //최대값 삭제
                if(!ms.empty()){
                    ms.erase(--ms.end());
                }
            }
        }
    }
    if(ms.empty()){
        answer[0]=0;
        answer[1]=0;
    }
    else{
        answer[1]=*ms.begin();
        answer[0]=*(--ms.end());
    }
    return answer;
}