#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
int N;
int answer = 0;
void dfs(int idx, int cnt, vector<int> num, vector<vector<int>> &q, vector<int> &ans){
    // 1부터 n까지 5개 고르는 조합
    if(cnt==5){
        // 지금 조합 num과 q를 비교해서 일치하는 갯수가 ans
        for(int i=0;i<q.size();i++){
            set<int> s;
            // q의 i번째 리스트 들어감
            for(int j=0;j<5;j++){
                s.insert(q[i][j]);
                s.insert(num[j]);
            }
           
            if((10-s.size())!=ans[i]) {
                // 응답이랑 갯수 같지않은 경우 return
                return;
            }
        }
        answer++;
        return;
    }
    for(int i=idx;i<=N;i++){
        num.push_back(i);
        dfs(i+1, cnt+1, num, q, ans);
        num.pop_back();
    }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    vector<int> num;
    dfs(1, 0, num, q, ans);
    return answer;
}