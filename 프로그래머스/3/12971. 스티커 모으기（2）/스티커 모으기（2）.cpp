#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp0[100001]; // 0번째를 떼는 경우
int dp1[100001]; // 1번째를 떼는 경우
int solution(vector<int> sticker)
{
    int n = sticker.size();
    if(sticker.size()==1) return sticker[0];
    if(sticker.size()==2) return max(sticker[0], sticker[1]);
    // 0번째 index를 뗌
    dp0[0]=sticker[0];
    dp0[1]=dp0[0];
    for(int i=2;i<n-1;i++){
        // i를 뗌 = dp[i-2]+sticker[i] vs i를 떼지 않고 dp[i-1]
        dp0[i]=max(dp0[i-1], dp0[i-2]+sticker[i]);
    }
    dp1[0]=0;
    dp1[1]=sticker[1];
    for(int i=2;i<n;i++){
        dp1[i]=max(dp1[i-1], dp1[i-2]+sticker[i]);
    }
    
    return max(dp0[n-2], dp1[n-1]);
}