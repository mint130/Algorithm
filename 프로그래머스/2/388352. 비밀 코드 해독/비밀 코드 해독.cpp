#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int num[5];
int answer = 0;
void dfs(int idx, int cnt, int n, vector<vector<int>> &q, vector<int> &ans){
    // n중에 30을 조합으로 
    if(cnt==5){
        bool flag = 0;
        for(int i=0;i<q.size();i++){
            set<int> s;
            for(int j=0;j<5;j++){
                s.insert(num[j]);
                s.insert(q[i][j]);
            }
            // 겹치는 갯수
            int cnt = 10-s.size();
            // 응답이랑 갯수 같은지 확인
            if(cnt!=ans[i]){
                flag = 1;
                break;
            }
        }
    
        // 입력이랑 다 일치하면 경우 증가
        if(!flag){
            answer++;
        }

        return;
    }
    
    for(int i=idx;i<=n;i++){
        num[cnt]=i;
        dfs(i+1, cnt+1, n, q, ans);
    }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    dfs(1, 0, n, q, ans);
    
    return answer;
}