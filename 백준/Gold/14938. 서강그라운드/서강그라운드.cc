#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r; //지역 갯수, 수색 범위, 길의 갯수 
int ans = 0;
int item[101];
vector<pair<int, int>> v[101];
const int INF = 987654321;

int dijkstra(int st){
    //dist는 st에서부터의 최단 거리 저장
    int dist[101];
    fill(dist, dist+n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    //시작점
    pq.push({0, st});
    dist[st]=0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost>dist[cur]) continue; //dist[cur]보다 현재 거리가 더 길다 -> 이미 처리됨 
        for(auto nxt: v[cur]){
            if(cost+nxt.first<dist[nxt.second]){
                dist[nxt.second]=cost+nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }

    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(dist[i]<=m){
            sum+=item[i];
        }
    }
    return sum;
}

int main () {
    cin>>n>>m>>r;
   
    //아이템
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        item[i]=t;
    }

    for(int i=0;i<r;i++){
        int a, b, l;
        cin>>a>>b>>l;
        v[a].push_back({l, b});
        v[b].push_back({l, a});
    }

    for(int i=1;i<=n;i++){
        ans=max(ans, dijkstra(i));
    }

    cout<<ans;
}