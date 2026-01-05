#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp1[100001]; // 0번째를 떼는 경우
int dp2[100001]; // 1번째를 떼는 경우
int solution(vector<int> sticker)
{
    int answer =0;
    if(sticker.size()==1) return sticker[0];
    if(sticker.size()==2) return max(sticker[0], sticker[1]);
    dp1[0]=sticker[0];
    dp1[1]=dp1[0]; // 0번쨰를 뗴고 1번째를 안 뗌
    for(int i=2;i<sticker.size()-1;i++){
        // i-2번째를 떼고 i번째를 뗌
        // i-1번째를 떼고 i번째를 안똄
        dp1[i]=max(dp1[i-2]+sticker[i], dp1[i-1]);
    }
    dp2[0]=0;
    dp2[1]=sticker[1]; // 0번째를 안 떼고 1번째를 뗌
    for(int i=2;i<sticker.size();i++){
        dp2[i]=max(dp2[i-2]+sticker[i], dp2[i-1]);
    }
    return max(dp1[sticker.size()-2], dp2[sticker.size()-1]);
}