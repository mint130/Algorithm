#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int answer = 0;
bool visited[18][18][18]; // i번 노드에 j개의 양 k개의 늑대로 방문한 적 있는지
vector<int> v[18]; // v[p]
void dfs(int cur, vector<int> &info, int sheep, int wolf) {
    answer = max(answer, sheep);
    for(auto nxt:v[cur]){
        if(info[nxt]==0 && !visited[nxt][sheep+1][wolf]){
            visited[nxt][sheep+1][wolf]=1;
            // 빈 노드로 바꿈
            info[nxt]=-1;
            dfs(nxt, info, sheep+1, wolf);
            // 원복
            info[nxt]=0;
            visited[nxt][sheep+1][wolf]=0;
        }
        else if(info[nxt]==1 && !visited[nxt][sheep][wolf+1] && sheep>wolf+1){
            visited[nxt][sheep][wolf+1]=1;
            info[nxt]=-1;
            dfs(nxt, info, sheep, wolf+1);
            info[nxt]=1;
            visited[nxt][sheep][wolf+1]=0;
        }
        else if(info[nxt]==-1 && !visited[nxt][sheep][wolf]){
            // 비었음 
            visited[nxt][sheep][wolf]=1;
            dfs(nxt, info, sheep, wolf);
            visited[nxt][sheep][wolf]=0;
        }
    }

}
int solution(vector<int> info, vector<vector<int>> edges) {

    for(int i=0;i<edges.size();i++){
        int p = edges[i][0];
        int c = edges[i][1];
        v[p].push_back(c);
        v[c].push_back(p);
    }
    // 양 얻음
    visited[0][1][0]=1;
    info[0]=-1;
    dfs(0, info, 1, 0);
    return answer;
}