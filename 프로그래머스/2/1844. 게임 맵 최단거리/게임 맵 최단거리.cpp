#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include <iostream>
using namespace std;
int n, m; 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int map[101][101]={0,};
int dist[101][101]={-1,};
int visited[101][101]={0};
queue <pair<int,int>> q;
//0은 벽, 1은 갈 수 있음

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n=maps.size();
    m=maps[0].size();

    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[i].size();j++)
        {
            map[i][j]=maps[i][j];
            
        }
    }
  
    memset(dist, -1, sizeof(dist)); 
    q.push({0,0});

    dist[0][0]=1; //시작 위치
    visited[0][0]=1; //방문
    //상대 위치는 n-1, m-1
    
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();
        //cout<<x<<" "<<y<<endl;
        if(x==n-1 && y==m-1) break;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
             
                if(visited[nx][ny]==0 && map[nx][ny]==1)
                {
                   
                    dist[nx][ny]=dist[x][y]+1;
                    visited[nx][ny]=1;
                    q.push({nx, ny});
                    
                }
            }
            
        }
    }
    answer=0;
    if(dist[n-1][m-1]==-1) answer=-1;
    else{
        answer=dist[n-1][m-1];
    }
    return answer;
}