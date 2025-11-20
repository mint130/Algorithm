#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[41][121]; // dp[i][j]: i번째 까지 왔을때 b의 흔적 j -> 이때 a의 흔적
int solution(vector<vector<int>> info, int n, int m) {
    for(int i=0;i<=info.size();i++){
        for(int j=0;j<m;j++){
            dp[i][j]=987654321;
        }
    }
    dp[0][0]=0;

    for(int i=1;i<=info.size();i++){
        int a = info[i-1][0];
        int b = info[i-1][1];
        for(int j=0;j<m;j++){
            // b의 무게를 늘려감
            // a가 훔침
            dp[i][j]=min(dp[i-1][j]+a, dp[i][j]);
            // b가 훔침
            if(j+b<m)
                dp[i][j+b]=min(dp[i-1][j], dp[i][j+b]);
        }
    }
    int answer = 987654321;
    for(int i=0;i<m;i++){
        answer =min(answer, dp[info.size()][i]);
    }
    
    return answer>=n?-1:answer;
}