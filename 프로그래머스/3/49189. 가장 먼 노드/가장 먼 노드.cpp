#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> adj[20002];
int dist[20002];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++){
        int st=edge[i][0];
        int en=edge[i][1];
        adj[st].push_back(en);
        adj[en].push_back(st); //이거 있어도 되는건가
    }
    memset(dist, -1, sizeof(dist));
 
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto nxt:adj[cur]){
            if(dist[nxt]!=-1) continue; //방문한 적 있음
            q.push(nxt);
            dist[nxt]=dist[cur]+1;
        }
    }
    int maxdist=*max_element(dist, dist+n+1);
    for(auto i:dist){
        if(i==maxdist) answer++;
    }
    return answer;
}