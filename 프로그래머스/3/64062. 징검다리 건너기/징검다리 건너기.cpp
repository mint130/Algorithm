#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool pass(vector<int> &stones, int k, int mid){
    // stones[i]<=mid인 것의 갯수가 연속해서 k를 넘으면 징검다리 건널 수 x
    int cnt = 0;
    for(int i=0;i<stones.size();i++){
        if(stones[i]<=mid){
            cnt++;
        }
        else {
            // cnt 초기화
            cnt = 0;
        }
        if(cnt==k){
            // 징검다리 넘을 수 x
            return false;
        }
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int st = 0;
    int en = 200000000;
    int mid = 0;
    while(st<=en){
        mid = (st+en)/2;
        if(pass(stones, k, mid)){
            // 징검다리 넘을 수 있음
            st = mid+1;
        }
        else en = mid-1; // 넘을 수 없음
        
    }

    return st;
}