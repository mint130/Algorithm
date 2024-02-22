#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> p; //응시자 좌표 들어가는 벡터
char board[6][6];
bool visit[6][6];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cx[4]={1,1,-1,-1};
int cy[4]={1,-1,1,-1};
int pnum=0; //응시자의 수
void clear(){
    //board초기화
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            visit[i][j]=0;
        }
    }
}
bool injection(int x, int y){
    for(int dir=0;dir<4;dir++){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
        if(board[nx][ny]=='P'){
            //인접한 위치에 응시자가 있으면 0넣고 break
            //cout<<"인접함"<<endl;;
            return true;
        }
    }
    return false;
}
bool cross(int x, int y) {
    for(int dir=0;dir<4;dir++){
        int nx=x+cx[dir];
        int ny=y+cy[dir];
        if(nx<0 || nx>=5 ||ny<0 || ny>=5) continue;
        if(board[nx][ny]=='P'){
            if(board[nx][y]=='O' || board[x][ny]=='O') {
                //cout<<"대각선"<<endl;
                return true;
            }
        }
        
    }
    return false;
}
bool two(int x, int y){
    for(int dir=0;dir<4;dir++){
        int nx=x+2*dx[dir];
        int ny=y+2*dy[dir];
        int px=x+dx[dir];
        int py=y+dy[dir];
        if(nx<0 || nx>=5 || ny<0 || ny>=5) continue;
        if(board[nx][ny]=='P'){
            //2칸 떨어진 곳에 응시자가 있는데 
            if(board[px][py]=='O'){
                cout<<"2칸"<<endl;
                return true;
            }
        }
    }
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int k=0;k<5;k++){
        p.clear();
        //대기실 수
        vector<string> s;
        s=places[k];
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                board[i][j]=s[i][j];
                if(s[i][j]=='P') p.push_back({i,j});
            }
        }
        bool flag=0; //flag가 1이면 거리두기 지키지 않음
        if(p.empty()){
            flag=0;
        }
        //응시자가 없으면 0넣고 break
        
        cout<<p.size()<<endl;
        for(int i=0;i<p.size();i++){
            
            
            int x=p[i].first;
            int y=p[i].second; 
            cout<<x<<" "<<y<<endl;
            //x, y는 p의 좌표
            //인접한 곳에 있는지 검사
            //대각선 위치에 있는지 검사
            //2칸 떨어진 위치에 있는지 검사
        
            visit[x][y]=1;
            if(injection(x, y) || cross(x, y) || two(x, y)) {
               //셋중 하나라도 true면 거리두기를 지키지 않음
               flag=1;          
            }
            //clear();
            
       }
    
        if(flag==1) answer.push_back(0);
        else answer.push_back(1);
        
    }
    return answer;
}