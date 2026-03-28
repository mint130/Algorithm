#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int dist[101][101];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int n, m;
int board[101][101];
vector<int> answer;
void bfs(int r, int c) {
    dist[r][c]=0;
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        sum+=board[x][y];
        q.pop();
        
        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]==-1) continue;
            if(dist[nx][ny]==-1) {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    answer.push_back(sum);
}
vector<int> solution(vector<string> maps) {
    n=maps.size();
    m=maps[0].length();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=-1;
            if(maps[i][j]=='X') board[i][j]=-1;
            else board[i][j]=maps[i][j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!=-1 && dist[i][j]==-1) bfs(i, j);
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}