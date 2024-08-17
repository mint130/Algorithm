#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool board[5][5];
map<int, pair<int, int>> m; //m[num]={x, y}
bool isR[5]; //n번째 행이 빙고인지
bool isC[5]; //n번째 열이 빙고인지
bool isB[2]; //0은 / 1은 \

int bingo = 0; //빙고의 갯수
//행검사
void row(int r){
    //r번째 행이 빙고인지
    for(int i=0;i<5;i++){
        if(board[r][i]) {
            //하나라도 1이면 빙고 아님
            return;
        }
    }
    //r번째 행이 빙고라면
    bingo++;
    isR[r]=1;
    
}
//열검사
void col(int c){
    //r번째 행이 빙고인지
    for(int i=0;i<5;i++){
        if(board[i][c]) {
            //하나라도 1이면 빙고 아님
            return;
        }
    }
    //r번째 행이 빙고라면
    bingo++;
    isC[c]=1;

}
// / 검사
void a(){
    for(int i=0;i<5;i++){
        if(board[4-i][i]) return;
    }
    bingo++;
    isB[0]=1;
}
// \ 검사
void b(){
    for(int i=0;i<5;i++){
        if(board[i][i]) return;
    }
    bingo++;
    isB[1]=1;

}
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int n;
            cin>>n;
            m[n]={i, j};
            board[i][j]=1;
        }
    }
    for(int i=1;i<=25;i++){
        int num;
        cin>>num; //사회자가 부르는 숫자
        //숫자 위치를 0으로
        int x, y = 0;
        x=m[num].first;
        y=m[num].second;
        board[x][y]=0;
        //이미 빙고인 행이나 열은 뛰어넘음
        //x행 검사
        if(!isR[x]) row(x);
        //y열 검사
        if(!isC[y]) col(y);
        //x==y라면 대각선 /검사
        if(!isB[0]) a();
        if(!isB[1]) b();
        if(bingo>=3){
            //빙고가 3이상
            cout<<i;
            return 0;
        }
    }
}