#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
char board[101][101];
int dist[101][101];
int n, m;
int rx, ry; // 처음
int gx, gy; // 목표
int solution(vector<string> board) {
    int answer = 0;
    n = board.size(); m = board[0].size();
    for(int i=0;i<board.size();i++){
        string s = board[i];
        for(int j=0;j<s.length();j++){
            board[i][j]=s[j];
            dist[i][j]=-1;
            if(s[j]=='R') {
                rx=i;
                ry=j;
            }
            else if(s[j]=='G') {
                gx=i;
                gy=j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({rx, ry});
    dist[rx][ry]=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        if(x==gx && y==gy) {
            return dist[x][y];
        }
        q.pop();
        for(int d=0;d<4;d++){
            int nx = x;
            int ny = y;
            while(1){
                // 장애물 만나거나 밖으로 나가기 전까지 한방향으로 
                int tx = nx+dx[d];
                int ty = ny+dy[d];
                
                if(tx<0||tx>=n||ty<0||ty>=m) break;
                if(board[tx][ty]=='D') break;
                
                nx = tx;
                ny = ty;
            }
            if(dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx, ny});
            }
            
        }
    }
    
    return -1;
}