#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>> pq;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(auto w:works){
        pq.push(w);
    }
    while(!pq.empty() && n>0){
        int num = pq.top();
        pq.pop();
        n--;
        if(num>0) pq.push(--num);
    }
    if(pq.size()>0){
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            answer+=num*num;
        }
    }
    return answer;
}