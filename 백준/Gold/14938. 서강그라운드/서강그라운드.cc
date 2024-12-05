#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r; //지역 갯수, 수색 범위, 길의 갯수 
int ans = 0;
int item[101];
int dp[101][101];
const int INF = 987654321;
int main () {
    cin>>n>>m>>r;
    //가장 처음 거리 배열 초기화 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=INF;
        }
    }
    //아이템
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        item[i]=t;
    }

    for(int i=0;i<r;i++){
        int a, b, l;
        cin>>a>>b>>l;
        dp[a][b]=min(dp[a][b], l);
        dp[b][a]=min(dp[b][a], l);
    }

    for(int i=1;i<=n;i++){
        dp[i][i]=0; //자기자신 
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            //i부터 시작, j에 도착 
            if(dp[i][j]<=m){
                sum+=item[j];
            }
        }
        ans=max(sum, ans);
    }
    cout<<ans;
}