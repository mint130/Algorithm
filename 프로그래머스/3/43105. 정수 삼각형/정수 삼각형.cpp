#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[502][502];
int board[502][502];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n=triangle.size(); //가장 마지막 변의 길이
    //dp[n][1]부터 dp[n][n]까지 중 가장 큰 값이 답
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            board[i][j]=triangle[i-1][j-1];
        }
    }

    dp[1][1]=board[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j-1]+board[i][j], dp[i-1][j]+board[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        answer=max(answer, dp[n][i]);
    }
    return answer;
}