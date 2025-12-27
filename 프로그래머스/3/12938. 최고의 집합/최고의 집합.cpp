#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s) {
        answer.push_back(-1);
        return answer;
    }
    vector<int> ans(n, s/n);
    // 남은것
    int num = s%n; // 추가로 +1씩 더해줘야함
    for(int i=0;i<num;i++){
        ans[i]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}