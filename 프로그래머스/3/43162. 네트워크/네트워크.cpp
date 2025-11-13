#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool visited[201];
vector<int> v[201];
int answer = 0;
void bfs(int cur){
    visited[cur]=1;
    queue<int> q;
    q.push(cur);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        
        for(auto nxt:v[c]){
            if(!visited[nxt]){
                visited[nxt]=1;
                q.push(nxt);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(computers[i][j]==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }   
        
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            bfs(i);
        }
    }
    return answer;
}