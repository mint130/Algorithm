#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int discount[8]; // idx번째 할인 비율
int d[4]={90, 80, 70, 60};
int t, m;
void dfs(int idx, vector<vector<int>> &users, vector<int> &emoticons) {
    if(idx==emoticons.size()){
        // 이모티콘 플러스 총 가입자 
        int member = 0;
        // 이모티콘 총 판매액
        int total = 0;
        
        for(int i=0;i<users.size();i++){
            int d = users[i][0]; // 비율
            int p = users[i][1]; // 가격 
            int sum = 0; // 사용자 사는 이모티콘 가격 합
            for(int j=0;j<emoticons.size();j++){
                // 할인율 discount[j]
                if(100-discount[j]>=d) {
                    // 일정 비율 이상 할인 -> 이모티콘 구매
                    sum+=discount[j]*emoticons[j]/100;
                }
            }
            if(sum>=p){
                // 일정 가격 이상 됨 -> 이모티콘 플러스 가입
                member++;
            }
            else {
                total+=sum;
            }
        }
        
        // 총 가입자 수가 기존 총 가입자 수보다 많으면 가입자 수, 매출액 갱신
        if(member>m) {
            m=member;
            t=total;
        }
        else if(member==m && total>t){ // 총 가입자 수가 기존 총 가입자 수와 같으면 매출액 갱신
            t=total;
        }
        return;
    }
    for(int i=0;i<4;i++){
        // 가격*i/100
        discount[idx]=d[i];
        dfs(idx+1, users, emoticons);
        discount[idx]=0;
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    // 일정 비율 이상 할인하는 이모티콘 모두 구매
    // 구매비용 합이 일정 가격이상 된다면 서비스에 가입
    dfs(0, users, emoticons);
    answer[0]=m; //가입수
    answer[1]=t; //매출액
    return answer;
}