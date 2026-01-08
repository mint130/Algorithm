#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool visited[18][18][18]; // 노드 늑대 양
vector<int> v[18];
int answer = 0;
void dfs(int cur, int sheep, int wolf, vector<int> &info) {
    answer = max(answer, sheep);
    for(auto nxt:v[cur]){
        // 갈 수 있는 노드 nxt
        if(info[nxt]==1 && wolf+1<sheep && !visited[nxt][wolf+1][sheep])
        {
            // 늑대가 있고 현재 늑대 갯수 +1 < 양
            visited[nxt][wolf+1][sheep]=1;
            // 늑대 없어짐
            info[nxt]=-1;
            dfs(nxt, sheep, wolf+1, info);
            // 원복
            info[nxt]=1;
            visited[nxt][wolf+1][sheep]=0;
        }
        else if(info[nxt]==0 && !visited[nxt][wolf][sheep+1]){
            // 양이 있는 경우
            visited[nxt][wolf][sheep+1]=1;
            info[nxt]=-1;
            dfs(nxt, sheep+1, wolf, info);
            info[nxt]=0;
            visited[nxt][wolf][sheep+1]=0;
        }
        else if(info[nxt]==-1 && !visited[nxt][wolf][sheep]){
            visited[nxt][wolf][sheep]=1;
            dfs(nxt, sheep, wolf, info);
            visited[nxt][wolf][sheep]=0;
        }
    }
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i=0;i<edges.size();i++){
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[0][0][1]=1; // 0번에는 항상 양이 있음
    info[0]=-1; // 빈칸
    dfs(0, 1, 0, info);
    return answer;
}