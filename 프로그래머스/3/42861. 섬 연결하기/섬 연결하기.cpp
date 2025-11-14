#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[101];
vector<pair<int, int>> v[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 거리, node
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<costs.size();i++){
        int st = costs[i][0];
        int en = costs[i][1];
        int cost = costs[i][2];
        v[st].push_back({cost, en});
        v[en].push_back({cost, st});
    }
    pq.push({0, 0});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        // 방문 했으면 pass
        if(visited[cur]) continue;
        // 방문, 비용 더함
        visited[cur]=1;
        answer+=cost;
        for(auto nxt:v[cur]){
            if(!visited[nxt.second]) pq.push({nxt.first, nxt.second});
        }
    }
    return answer;
}