#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>> v[201];
void dijkstra(int st, vector<int> &dist){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, st});
    dist[st]=0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[cur]<cost) continue;
        for(auto nxt:v[cur]){
            int node = nxt.second;
            int w = nxt.first;
            if(dist[node]>dist[cur]+w){
                dist[node]=dist[cur]+w;
                pq.push({dist[node], node});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 987654321;
    for(int i=0;i<fares.size();i++){
        int a = fares[i][0];
        int b = fares[i][1];
        int c = fares[i][2];
        v[b].push_back({c, a});
        v[a].push_back({c, b});
    }
    vector<int> aa(n+1, 987654321);
    // a -> 다른 노드
    dijkstra(a, aa);
    // b -> 다른 노드
    vector<int> bb(n+1, 987654321);
    dijkstra(b, bb);
    // s -> 다른 노드
    vector<int> ss(n+1, 987654321);
    dijkstra(s, ss);
    
    // 각각
    answer = ss[a]+ss[b];
    for(int i=1;i<=n;i++){
        int m = ss[i];
        int aaa = aa[i];
        int bbb = bb[i];
        if(aaa==987654321 || bbb==987654321) continue;
        answer = min({m+aaa+bbb, answer});
    }
   
    return answer;
}