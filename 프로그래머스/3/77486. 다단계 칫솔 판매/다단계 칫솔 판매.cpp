#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<string, string> ref; // 추천인
unordered_map<string, int> sell; // 멤버별 판매 금액
void dfs(string name, int money){
    if(name=="-"||money==0){
        // 더이상 나눠줄 수익금 x
        return;
    }
    int tmp = money * 0.1; //추천인한테 가는 이익
    sell[name]+=(money-tmp); 
    dfs(ref[name], tmp);
    
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i=0;i<enroll.size();i++){
        // enroll[i]의 추천인 referral[i]
        ref[enroll[i]]=referral[i];
    }
    for(int i=0;i<seller.size();i++){
        // seller[i]의 판매액 result[i]
        dfs(seller[i], amount[i]*100);
    }
    for(auto i:enroll){
        answer.push_back(sell[i]);
    }
    return answer;
}