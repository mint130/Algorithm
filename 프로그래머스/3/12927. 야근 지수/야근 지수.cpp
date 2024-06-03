#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    while(n){
        if(pq.empty()){
            return 0;
        }
        int num=pq.top();
        pq.pop();
        if(num!=0) pq.push(--num);
        n--;
    }
    while(!pq.empty()){
        answer+=pq.top()*pq.top();
        pq.pop();
    }
    return answer;
}