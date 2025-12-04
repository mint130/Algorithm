#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
multiset <int> ms; // 오름차순
vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    for(int i=0;i<operations.size();i++){
        char c = operations[i][0];
        if(c=='D'){
            if(operations[i][2]=='-'){
                //최솟값 삭제
                if(!ms.empty()) ms.erase(ms.begin());
            }
            else {
                //최댓값 삭제
                if(!ms.empty()) ms.erase(--ms.end());
            }
        }
        else {
            string s = operations[i].substr(1);
            int num = stoi(s);
            ms.insert(num);
        }
    }
    if(ms.empty()) {answer[0]=0; answer[1]=0;}
    else {
        answer[1]=*ms.begin();
        answer[0]=*(--ms.end());
    }
    
    return answer;
}