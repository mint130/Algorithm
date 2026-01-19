#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int board[101][101]; // 1이면 못감
int dist[101][101];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int ex, ey, lx, ly, sx, sy, n, m;
int bfs(int r, int c, int r2, int c2){
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist[i][j]=-1;
    }
    dist[r][c]=0;
    q.push({r, c});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x==r2 && y==c2){
            return dist[x][y];
        }
        q.pop();
        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]==-1 && !board[nx][ny]) {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    n=maps.size();
    m=maps[0].length();
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            if(maps[i][j]=='X') board[i][j]=1;
            if(maps[i][j]=='E') {
                ex=i; ey=j;
            }
            if(maps[i][j]=='S'){
                sx=i; sy=j;
            }
            if(maps[i][j]=='L'){
                lx=i; ly=j;
            }
        }
    }
    int a = bfs(lx, ly, sx, sy);
    int b = bfs(ex, ey, lx, ly);
    
    if(a==-1 || b==-1) return -1;
    else return a+b;
}