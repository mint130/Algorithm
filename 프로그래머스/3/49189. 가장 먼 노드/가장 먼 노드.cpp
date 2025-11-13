#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
vector<int> v[20001];
int dist[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    fill(dist, dist+n+1, -1);
    dist[1]=0;
    for(int i=0;i<edge.size();i++){
        int a = edge[i][0];
        int b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto nxt:v[cur]){
            if(dist[nxt]==-1){
                dist[nxt]=dist[cur]+1;
                q.push(nxt);
            }
        }
    }
    int m = -1;
    for(int i=1;i<=n;i++){
        m=max(m, dist[i]);
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==m) answer++;
    }
    
    return answer;
}