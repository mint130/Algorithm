#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[100002][2];
//dp[x][0]은 x점을 만들기 위한 다트수 -> 작아야 함
//dp[x][1]은 x점을 만들때 쓰는 싱글/볼 수 -> 커야 함
vector<int> solution(int target) {
    vector<int> answer(2);
    for(int i=0;i<=target;i++){
        dp[i][0]=987654321;
        dp[i][1]=0;
    }
    dp[0][0]=0; dp[0][1]=0;
    for(int i=1;i<=target;i++){
        //1부터 20까지 싱글
        for(int s=1;s<=20;s++){
            if(i-s<0) continue;
            if(dp[i][0]>dp[i-s][0]+1){
                dp[i][0]=dp[i-s][0]+1;
                dp[i][1]=dp[i-s][1]+1;
            }
            else if(dp[i][0]==dp[i-s][0]+1){
                dp[i][1]=max(dp[i][1], dp[i-s][1]+1);
            }
            
        }
        //2부터 40까지 더블
        for(int d=2;d<=40;d+=2){
            if(i-d<0) continue;
            if(dp[i][0]>dp[i-d][0]+1){
                dp[i][0]=dp[i-d][0]+1;
                dp[i][1]=dp[i-d][1];
            }
        }
        //3부터 60까지 트리플
        for(int t=3;t<=60;t+=3){
            if(i-t<0) continue;
            if(dp[i][0]>dp[i-t][0]+1){
                dp[i][0]=dp[i-t][0]+1;
                dp[i][1]=dp[i-t][1];
            }
        }
        //50은 불
        if(i-50<0) continue;
        if(dp[i][0]>dp[i-50][0]+1){
            dp[i][0]=dp[i-50][0]+1;
            dp[i][1]=dp[i-50][1]+1;
        }
        else if(dp[i][0]==dp[i-50][0]+1){
            dp[i][1]=max(dp[i][1], dp[i-50][1]+1);
        }
    }

    
    answer[0]=dp[target][0];
    answer[1]=dp[target][1];
    return answer;
}