#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;
long long dp[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0]=1;
    
    for(int i=0;i<money.size();i++){
        int coin = money[i];
        for(int j=1;j<=n;j++){
            if(j>=coin) dp[j]+=(dp[j-coin]%1000000007);
        }
    }

    return dp[n];
}