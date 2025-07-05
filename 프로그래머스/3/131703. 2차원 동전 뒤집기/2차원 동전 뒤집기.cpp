#include <string>
#include <vector>
#include <iostream>

using namespace std;
int n, m;
int answer = 987654321;
int board[11][11];
int result[11][11];
void row(int r){
    // r 행을 뒤집음
    for(int i=0;i<m;i++){
        if(board[r][i]==1) board[r][i]=0;
        else board[r][i]=1;
    }
}
void col(int c){
    // c 열을 뒤집음
    for(int i=0;i<n;i++){
        if(board[i][c]==1) board[i][c]=0;
        else board[i][c]=1;
    }
}
bool check() {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!=result[i][j]) return false;
        }
    }
    return true;
}
void dfs(int cnt, int res){
    if(cnt==n+m){
        if(check()) answer = min(answer, res);
        return;
    }
    
    int tmp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=board[i][j];
        }
    }
    dfs(cnt+1, res); //뒤집지 않음
    if(cnt<n){
        // 행을 뒤집는다
        row(cnt);
    }
    else {
        // 열을 뒤집는다
        int r = cnt-n;
        col(r);
    }
    dfs(cnt+1, res+1); //뒤집음
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j]=tmp[i][j];
        }
    }
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    n = beginning.size();
    m = beginning[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j]=beginning[i][j];
            result[i][j]=target[i][j];
        }
    }
    dfs(0, 0);
    if(answer==987654321) answer=-1;
    return answer;
}