#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int n, t, answer;
int num[22];
int sum=0;
void dfs(int k, int sum){
    if(k==n) {
        if(sum==t) answer++;
        sum=0;
        return;
    }
    //k번째까지씀
    dfs(k+1, sum+num[k+1]);
    dfs(k+1, sum-num[k+1]);
    
}
int solution(vector<int> numbers, int target) {
    n=numbers.size();
    answer=0;
    t=target;
    for(int i=0;i<n;i++) num[i+1]=numbers[i];
    dfs(0,0);
    
    return answer;
}