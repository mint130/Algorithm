#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool clean[16];
bool used[9];
int w;
int ans = 987654321; // 가장 적게 쓰는 친구 수
void dfs(int cur, int start, int cnt, vector<int> &week, vector<int> &dist) {
    // weak의 갯수
    if(cnt>=ans) return; // 친구 이미 더 많이 씀 -> 더 볼 필요 x
    if(cur>=start+w){
        // 외벽 다 덮음
        ans=min(ans, cnt);
        return;
    }
    for(int i=0;i<dist.size();i++){
        if(used[i]) continue;
        // 안 쓴 친구 선택 
        used[i]=1;
        // 친구가 커버할 수 있는 범위
        int end = week[cur]+dist[i];
        int nxt = cur;
        // 다음 친구가 와야하는 시작점 nxt 찾음
        while(nxt<start+w && week[nxt]<=end) nxt++;
        
        dfs(nxt, start, cnt+1, week, dist);
        
        used[i]=0;
    }
    
    
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    w = weak.size();
    for(int i=0;i<w;i++){
        weak.push_back(weak[i]+n);
    }

    sort(dist.begin(), dist.end());
    for(int st=0;st<w;st++) {
        // st을 늘려가면서
        fill(used, used+9, 0);
        dfs(st,st,0,weak,dist);
    }
    if(ans==987654321) return -1;
    else return ans;
}