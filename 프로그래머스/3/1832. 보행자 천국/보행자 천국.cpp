#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int MOD = 20170805;
int dp[501][501][2] ={0};
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    memset(dp, 0, sizeof(dp));

    dp[0][0][0]=1; // 아래로
    dp[0][0][1]=0; // 오른쪽으로 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) continue;
            if(city_map[i][j]==1) continue; // 못 지나감
            // 위에서 내려옴
            if(i>0 && city_map[i-1][j]!=1) {
                dp[i][j][0]=dp[i-1][j][0]; // 같은 위에서 내려온 경우의 수
                if(city_map[i-1][j]==0){
                    // 옆에서 내려온 것도 포함
                    dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][1])%MOD;
                }
            }
            // 왼쪽에서 옴
            if(j>0 && city_map[i][j-1]!=1){
                dp[i][j][1]=dp[i][j-1][1];
                if(city_map[i][j-1]==0){
                    dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][0])%MOD;
                }
            }
        }
    }
    return (dp[m-1][n-1][0]+dp[m-1][n-1][1])%MOD;
}