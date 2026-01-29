#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long dp0[1000001]; // 0번을 털었을 떄
long long dp1[1000001]; // 1번을 털었을 때
int n;
int solution(vector<int> money) {
    int answer = 0;
    n = money.size();
    
    // dp[i] -> max(i-1, i-2+money)
    dp0[0]=money[0];
    dp0[1]=dp0[0];
    dp1[0]=0;
    dp1[1]=money[1];
    for(int i=1;i<n-1;i++){
        dp0[i]=max(dp0[i-2]+money[i], dp0[i-1]);
    }
    for(int i=2;i<n;i++){
        dp1[i]=max(dp1[i-2]+money[i], dp1[i-1]);
    }
    
    
    return max(dp0[n-2], dp1[n-1]);
}