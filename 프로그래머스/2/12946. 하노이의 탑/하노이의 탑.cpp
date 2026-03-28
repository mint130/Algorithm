#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 1~n-1까지 2번으로 옮김
// n번째를 3번으로 옮김
// 1~n-1을 3번으로 옮김
vector<vector<int>> answer;
vector<int> ans(2);
void dfs(int n, int from, int to, int temp){
    if(n==1){
        ans[0]=from;
        ans[1]=to;
        answer.push_back(ans);
        return;
    }
    dfs(n-1, from, temp, to);
    ans[0]=from;
    ans[1]=to;
    answer.push_back(ans);
    dfs(n-1, temp, to, from);
}
vector<vector<int>> solution(int n) {
    dfs(n, 1, 3, 2);
    return answer;
}