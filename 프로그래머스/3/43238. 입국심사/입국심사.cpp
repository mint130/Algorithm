#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long st = 0;
    long long en = (long long)times.back()*n;
    long long mid = (st+en)/2;
    while(st<=en){
        // 매 times마다 mid만큼 할당
        mid = (st+en)/2;
        long long cnt = 0;
        
        for(int i=0;i<times.size();i++){
            cnt+=mid/times[i]; // 줄 서있는 사람
            if(cnt>n) break;
        }
        if(cnt<n){
            st = mid+1;
        }
        else {
            en = mid-1;
            answer = mid;
        }
            
    }
    
    
    return answer;
}