#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m, ans;
bool visited[6][6];
int board[6][6];
void dfs(int cur, int sum){
    ans=max(sum, ans);
    
    for(int i=cur;i<n*m;i++){
        int r = i/m;
        int c = i%m;
        
        if(visited[r][c]) continue; 
        visited[r][c]=true;

        //위, 오른쪽 
        if(r-1>=0 && c+1<m && !visited[r-1][c] && !visited[r][c+1]){
            visited[r-1][c]=true;
            visited[r][c+1]=true;
            dfs(i+1, sum+board[r][c]*2 + board[r-1][c]+board[r][c+1]);
            visited[r-1][c]=false;
            visited[r][c+1]=false;
            
        }

        //위, 왼쪽
        if(r-1>=0 && c-1>=0 && !visited[r-1][c] && !visited[r][c-1]){
            visited[r-1][c]=true;
            visited[r][c-1]=true;
            dfs(i, sum+board[r][c]*2+board[r-1][c]+board[r][c-1]);
            visited[r-1][c]=false;
            visited[r][c-1]=false;
        } 
        //아래, 오른쪽
        if(r+1<n && c+1<m && !visited[r+1][c] && !visited[r][c+1]){
            visited[r+1][c]=true;
            visited[r][c+1]=true;  
            dfs(i, sum+board[r][c]*2+board[r+1][c]+board[r][c+1]);
            visited[r+1][c]=false;
            visited[r][c+1]=false;
        }

        //아래, 왼쪽
        if(r+1<n && c-1>=0 && !visited[r+1][c] && !visited[r][c-1]){
            visited[r+1][c]=true;
            visited[r][c-1]=true;
            dfs(i, sum+board[r][c]*2+board[r+1][c]+board[r][c-1]);
            visited[r+1][c]=false;
            visited[r][c-1]=false;

        }
        visited[r][c]=false;

    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    dfs(0, 0);
    cout<<ans;
}