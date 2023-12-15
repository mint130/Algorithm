#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char map[102][102]={0};
int visited[102][102]={0};
queue<pair<int, int>> q;
int finishX, finishY;
int leverX, leverY;
int startX, startY;
int N, M;
int BFS(int firstX, int firstY, int endX, int endY){
    queue<pair<int, int>> q;
    q.push({firstX, firstY});
   
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();
       
        if(x==endX && y==endY){
            
            return visited[x][y];
            
        }
        for(int i=0;i<4;i++){
        
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(map[nx][ny]!='X'){
                    if(visited[nx][ny]==0){
                        visited[nx][ny]=visited[x][y]+1;
                        q.push({nx, ny});
                    }
                }
            }
           
        }
        
    }
    return visited[endX][endY];
    
}
int solution(vector<string> maps) {
    
    N=maps.size(); //세로 사이즈
    M=maps[0].length();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j]=maps[i][j];
            visited[i][j]=0;
            if(map[i][j]=='S'){
                //시작 지점
                startX=i;
                startY=j;
            }
            if(map[i][j]=='E'){
                finishX=i;
                finishY=j;
                //도착 지점
            }
            if(map[i][j]=='L'){
                leverX=i;
                leverY=j;
                //레버 지점
            }
        }
    }
    //레버를 먼저 당겨야 한다
    int lever=BFS(startX, startY, leverX, leverY);
   
    if(lever==0){
        cout<<"lever "<<lever<<endl;
        return -1;
        //레버를 찾을 수 없으면 return -1
    } else {
        //레버를 찾았다면
        
        memset(visited, 0, sizeof(visited));
       
        //방문한 배열 초기화해주기
       
        int exit=BFS(leverX, leverY, finishX, finishY);
        cout<<"lever "<<lever<<" exit "<<exit<<endl;
        if(exit==0) return -1;
        else {
            return lever+exit;
        }
       
        
        
    }
    
}