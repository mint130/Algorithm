#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1}; // 오 아래 왼 위
int dist[26][26][4];
int n;

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++) dist[i][j][k]=987654321;
        }
    }
    dist[0][0][0]=0;
    dist[0][0][1]=0;
    queue<pair<pair<int, int>, int>> q; // x, y, dir
    q.push({{0, 0}, 0});
    q.push({{0, 0}, 1});
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        
        q.pop();
        
        if(x==n-1 && y==n-1){
            answer = min(answer, dist[x][y][dir]);
        }
        
        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=n || board[nx][ny]) continue;
            int cost = dist[x][y][dir]; // 지금 cost
            if(d==dir){
                cost += 100;
            }
            else {
                cost += 600;
            }
            if(cost<=dist[nx][ny][d]){
                dist[nx][ny][d]=cost;
                q.push({{nx, ny}, d});
            }
            
        }
    }
    return answer;
}