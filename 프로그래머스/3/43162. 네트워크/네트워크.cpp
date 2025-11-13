#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool visited[201];
vector<int> v[201];
int answer = 0;
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
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            bfs(i, computers);
        }
    }
    return answer;
}