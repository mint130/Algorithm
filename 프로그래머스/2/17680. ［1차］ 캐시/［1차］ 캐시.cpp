#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> dq;
    for(string city:cities){
        string str = "";
        for(char c:city){
            str+=toupper(c); //대소문자 구분x
        }
        auto it = find(dq.begin(), dq.end(), str);
        if(it!=dq.end()){
            //hit
            dq.erase(it); // 기존 값 제거
            answer+=1;
            dq.push_back(str);
        }
        else {
            //miss
            answer+=5;
            dq.push_back(str);
            if(dq.size()>cacheSize) dq.pop_front();
        }
    }
    return answer;
}