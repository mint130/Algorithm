#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[201];
void bfs(int cur, vector<vector<int>> computers){
    visited[cur]=1;
    queue<int> q;
    q.push(cur);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(int i=0;i<computers.size();i++){
            if(!visited[i] && computers[c][i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            bfs(i, computers);
        }
    }
    return answer;
}