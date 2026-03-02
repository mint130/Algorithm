#include <string>
#include <vector>
#include <iostream>
using namespace std;
int status[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int sum;
int ans = 987654321;
vector<int> v;
vector<int> m;
void dfs(int cnt, vector<int> &picks) {
    if(cnt==sum) {
        int idx = 0;
        int tired = 0; // 피로도
        int cnt = 0; // 캔 갯수
        for(int i=0;i<m.size();i++){
            // 현재 광물 m[i], 현재 곡괭이 v[idx]
            tired+=status[v[idx]][m[i]];
            cnt++;
            if(cnt%5==0) idx++; //곡괭이 바꿈
            if(idx==v.size()) break; // 끝
        }
        ans=min(ans, tired);
        return;
    }
    for(int i=0;i<3;i++){
        if(picks[i]>0){
            picks[i]--;
            v.push_back(i);
            dfs(cnt+1, picks);
            v.pop_back();
            picks[i]++;
        }
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    sum=picks[0]+picks[1]+picks[2];
    for(int i=0;i<minerals.size();i++){
        if(minerals[i]=="diamond"){
            m.push_back(0);
        }
        else if(minerals[i]=="iron"){
            m.push_back(1);
        }
        else m.push_back(2);
    }
    dfs(0, picks);
    
    
    return ans;
}