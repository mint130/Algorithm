#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
int dist[501][501]; 
int n, m;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int idx = 0;
vector<int> v;
int bfs(int r, int c, vector<vector<int>> &land){
    dist[r][c]=0;
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        land[x][y]=idx;
        cnt++;
        q.pop();
        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]==-1 && land[nx][ny]!=0) {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==-1 && land[i][j]!=0){
                idx++;
                int c = bfs(i, j, land);
                v.push_back(c);
                //sz[idx]=bfs(i, j, land); // idx번째의 칸 갯수
            }
        }
    }
    
    for(int i=0;i<m;i++){
        
        int sum = 0; // 그 행의 석유량
        set<int> visited;
        for(int j=0;j<n;j++){
            // i열의 j행 내려가면서 
            int num = land[j][i];
            int sz = v[num-1];
            if(num && visited.count(num)==0){
                visited.insert(num);
                sum+=sz;
                //sum+=sz[land[j][i]];
            }
        }
        answer =max(answer, sum);
    }
    return answer;
}