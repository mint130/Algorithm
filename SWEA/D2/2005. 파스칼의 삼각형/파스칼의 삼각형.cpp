#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		int dp[11][11];
        int n;
        cin>>n;
        dp[0][0]=0;
        for(int i=0;i<=n;i++){
        	dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=i;j++){
            	if(j==i){
                	dp[i][j]=1;
                }
                else {
                	dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
               
            }
        }
        cout<<"#"<<test_case<<"\n";
		for(int i=1;i<=n;i++){
        	for(int j=1;j<=i;j++){
            	cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}