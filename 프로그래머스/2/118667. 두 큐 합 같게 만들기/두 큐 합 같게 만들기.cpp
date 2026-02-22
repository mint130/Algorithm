#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v;
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 987654321;
    int n = queue1.size();
    long long sum = accumulate(queue1.begin(), queue1.end(), 0L); // 찾는 숫자
    sum+=accumulate(queue2.begin(), queue2.end(), 0L);
    sum/=2;
    for(auto i:queue1){
        v.push_back(i);
    }
    for(auto i:queue2){
        v.push_back(i);
    }
    int len = n*2;
    int st = 0;
    int en = 0;
    int mid = n-1; // 중간
    long long ans = v[0];
    int cnt = 0;
    while(st<=en && en<len){
        if(ans<=sum){
            if(ans==sum){
                if(en>=mid){
                    cnt = en - mid + st;
                    answer = min(answer, cnt);
                }
            }
            en++;
            ans+=(long long)v[en];
        }
        else {
            ans-=(long long)v[st];
            st++;
        }
    }
    return answer==987654321?-1:answer;
}