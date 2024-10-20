#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, t, ans; //t는 초 
int board[51][51];
int tx, bx; //공기청정기 위치 y는 0
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
queue<pair<int ,int>> q; 
void top(){
    //위에서 아래 
    for(int i=tx-1;i>=1;i--){
        board[i][0]=board[i-1][0];
    }
    //<-
    for(int i=0;i<c-1;i++){
        board[0][i]=board[0][i+1];
    }
    //아래서 위
    for(int i=0;i<=tx-1;i++){
        board[i][c-1]=board[i+1][c-1];
    }
    //->
    for(int i=c-1;i>=1;i--){
        board[tx][i]=board[tx][i-1];
    }
    board[tx][1]=0;

}
void down(){

    //아래에서 위 
    for(int i=bx+1;i<r-1;i++){
        board[i][0]=board[i+1][0];
    }
    //<-
    for(int i=0;i<c-1;i++){
        board[r-1][i]=board[r-1][i+1];
    }
    //위에서 아래
    for(int i=r-1;i>=bx+1;i--){
        board[i][c-1]=board[i-1][c-1];
    }
    //->
    for(int i=c-1;i>=1;i--){
        board[bx][i]=board[bx][i-1];
    }
    board[bx][1]=0;
}
int main(){
    
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j]==-1){
                //공기청정기 위치 
                if(tx==0) tx=i;
                else bx=i;
            }
            else if(board[i][j]!=0){
                q.push({i, j});
            }
        }
    }

    while(t){
        //t초동안 진행 
        //미세먼지 확산 
        queue<pair<pair<int, int> , int>> q2; //확산 된 위치와 a 담음 
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int A = board[x][y]; //현재 미세먼지 
            q.pop();
            int cnt = 0;
            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx<0||nx>=r||ny<0||ny>=c) continue;
                if(board[nx][ny]==-1) continue;
                //board[nx][ny]+=A/5; //더함 
                q2.push({{nx, ny}, A/5});
                cnt++; //확산된 갯수 
            }
            //확산하지 않았으면 그대로, 기존 위치의 미세먼지 양만 바꿈 
            if(cnt!=0) board[x][y]-=A/5*cnt;
        }
        //확산된 칸의 미세먼지 더해줌
        while(!q2.empty()){
            int x = q2.front().first.first;
            int y = q2.front().first.second;
            int a = q2.front().second;

            q2.pop();

            board[x][y]+=a;            
        }
        
        //공기청정기 작동 
        //위로 
        top();

        //아래로 
        down();


        //큐에 다시 집어넣음
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==-1) continue;
                q.push({i, j});
            }
        }

        t--;
    }
    //미세먼지의 양 측정 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]==-1) continue;
            ans+=board[i][j];
        }
    }
    
    cout<<ans;
}