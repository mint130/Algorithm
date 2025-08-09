#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int intensity[50001];
vector<pair<int, int>> v[50001];
bool isSummit[50001]; // 봉우리인지
vector<pair<int, int>> ans;
void dijkstra(vector<int> gates){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 가중치, 목적지
    for(auto g:gates){
        pq.push({0, g});
        intensity[g]=0;
    }
    while(!pq.empty()){
        int cur =pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(intensity[cur]<cost) continue;
        if(isSummit[cur]){
            // 봉우리에 도달
            ans.push_back({cost, cur}); //봉우리 오르는데 드는 비용, 산봉우리 번호
            continue;
        }

        for(auto nxt:v[cur]){
            int node = nxt.second;
            int weight = nxt.first;
            
            if(intensity[node]==-1 || max(cost, weight)<intensity[node]) {
                intensity[node]=max(cost, weight);
                pq.push({intensity[node], node});
            } 
        }
    }
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    sort(summits.begin(), summits.end());
    for(int i=0;i<summits.size();i++){
        int node = summits[i];
        isSummit[node]=1;
    }
    for(int i=0;i<paths.size();i++){
        int st = paths[i][0];
        int en = paths[i][1];
        int cost = paths[i][2];
        v[st].push_back({cost, en});
        v[en].push_back({cost, st});
    }
    fill(intensity, intensity+n+1, -1);
    sort(gates.begin(), gates.end());
    dijkstra(gates);
    sort(ans.begin(), ans.end());
    answer[0]=ans[0].second;
    answer[1]=ans[0].first;
    return answer;
}