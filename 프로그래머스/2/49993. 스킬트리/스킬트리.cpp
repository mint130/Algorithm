#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string sk:skill_trees) {
        bool flag = 0;
        int idx = 0; // skill의 idx -> 순서대로 증가해야함
        for(int i=0;i<sk.length();i++){
            auto it = skill.find(sk[i]);
            if(it!=string::npos) {
                // 존재함
                if(it!=idx) {
                    flag = 1;
                    break;
                }
                else {
                    idx++;
                }
            }
        
        }
        if(!flag) answer++;
    }
    return answer;
}