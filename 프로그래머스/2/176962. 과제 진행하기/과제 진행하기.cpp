#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int totime(string s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h*60+m;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<pair<int, int>, string>> v; // {{시작시간, 소요시간}, 과목}
    stack<pair<int, string>> s; // {남은시간, 과목}
    for(int i=0;i<plans.size();i++){
        string s = plans[i][0];
        int st = totime(plans[i][1]);
        v.push_back({{st, stoi(plans[i][2])}, s});
    }
    sort(v.begin(), v.end());

    for(int i=0;i<v.size()-1;i++){
        string name = v[i].second;
        int st = v[i].first.first;
        int en = st+v[i].first.second;

        int nxt = v[i+1].first.first;
        if(nxt<en){
            // 과제 못끝냄
            int remain = en-nxt;
            s.push({remain, name});
        }
        else {
            // 다음 시작전에 현재 과제를 끝냄 
            answer.push_back(name);
            int free = nxt-en; // 남은시간
            while(!s.empty() && free>0){
                // nxt전에 끝나는 과제들 pop
                string sname = s.top().second;
                int remain= s.top().first; // 남은 시간
                s.pop();

                if(remain<=free) {
                    free-=remain;
                    answer.push_back(sname);
                }
                else {
                    remain-=free;
                    free=0;
                    s.push({remain, sname});
                }
            }
            
        }
    }
    
    answer.push_back(v.back().second);
        
    while(!s.empty()){
        answer.push_back(s.top().second);
        s.pop();
    }
    return answer;
}