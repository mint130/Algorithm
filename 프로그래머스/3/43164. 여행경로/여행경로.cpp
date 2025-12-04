#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool used[10001];
vector<string> answer;
bool ans;
void dfs(string cur, int cnt, vector<vector<string>> & tickets){
    answer.push_back(cur);
    if(cnt==tickets.size()){
        ans = 1;
        return;
    }
    for(int i=0;i<tickets.size();i++){
        if(used[i]) continue;
        string st = tickets[i][0];
        string en = tickets[i][1];
        if(st==cur){
            used[i]=1;
            dfs(en, cnt+1, tickets);
            if(!ans){
                answer.pop_back();
                used[i]=0;
            }

        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    dfs("ICN", 0, tickets);
    return answer;
}