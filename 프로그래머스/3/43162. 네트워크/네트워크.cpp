#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> node[202];
queue<int> q;
bool visited[202];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(computers[i][j]){
                node[i].push_back(j);
            }
        }
    }

    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            q.push(i);
            visited[i]=1;
            answer++;
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                for(auto nxt:node[cur]){
                    if(!visited[nxt]){  
                        q.push(nxt);
                        visited[nxt]=1;
                    }
                }
            }
            
        }

    }
    
    
    return answer;
}