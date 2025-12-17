#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[101][101];
int board[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0;i<puddles.size();i++){
        int a = puddles[i][0];
        int b = puddles[i][1];
        board[b-1][a-1]=1; // 연못
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            if(board[i][j]) continue;
            
            if(i>0 && board[i-1][j]==0) {
                dp[i][j]+=dp[i-1][j];
            }
            if(j>0 && board[i][j-1]==0){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=1000000007;
            
        }
    }
   
    return dp[n-1][m-1];
}