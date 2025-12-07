#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<int> v[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {이동거리, nxt}
int dist[100001];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    fill(dist, dist+n+1, 987654321);
    for(int i=0;i<roads.size();i++){
        int a = roads[i][0];
        int b = roads[i][1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    pq.push({0, destination});
    dist[destination]=0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int d = pq.top().first;
        
        pq.pop();

        if(dist[cur]<d) continue;
        for(auto nxt:v[cur]){
            if(d+1<dist[nxt]){
                dist[nxt]=d+1;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    for(auto i: sources){
        if(dist[i]==987654321) dist[i]=-1;
        answer.push_back(dist[i]);
    }
    return answer;
}