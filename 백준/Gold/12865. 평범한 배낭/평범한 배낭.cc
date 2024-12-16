#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k; //물건 n, 무게 k, 무게는 최대 k
int value[101]; 
int weight[101];
int dp[101][100002]; //dp[i][k] 최대 k무게까지 담을 수 있고 i까지 고려했을 때의 최대 가치
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int w, v;
        cin>>w>>v;
        value[i]=v;
        weight[i]=w;
    }
    for(int i=0;i<=k;i++){
        //초기화: 어떤 물건도 담지 않음
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        //초기화: 베낭의 무게 0 
        dp[i][0]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            //현재 물건의 번호 i, 가방의 무게 k
            if(j<weight[i]){
                //현재 물건의 무게가 가방 무게 k보다 크면 못담는다
                dp[i][j]=dp[i-1][j];
            }
            else {
                //현재 i의 물건을 담거나 담지 않거나 중 더 가치가 큰 것
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }

    cout<<dp[n][k];
}