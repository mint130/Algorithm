#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int> m; // 해당 보석의 갯수 저장
vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<pair<int, pair<int, int>>> ans; // 구간, 처음, 끝
    set<string> s;
    for(auto i:gems){
        s.insert(i);
    }
    int sz = s.size(); // 보석 종류 갯수
    int st = 0;
    int en = 0;
    for(auto i:gems){
        m[i]++;
        if(m.size()==sz) break; // 처음 모든 보석의 종류를 채우는 위치 en
        en++; 
    }
    ans.insert({en-st, {st+1, en+1}});
    while(st<=en && en<gems.size()){
        string cur = gems[st]; 
        m[cur]--; st++;
        if(m[cur]==0){
            // 다시 cur이 나올때까지 ++
            en++;
            for(;en<gems.size();en++){
                m[gems[en]]++;
                if(m[cur]>0) {
                    break;
                }
            }
        }
        ans.insert({en-st, {st+1, en+1}});
    }
   
    answer[0]=ans.begin()->second.first;  // 가장 처음 
    answer[1]=ans.begin()->second.second; // 가장 처음
    return answer;
}