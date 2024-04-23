#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n=scoville.size();
    for(int i=0;i<n;i++){
        pq.push(scoville[i]);
    }
    while(pq.size()>=2 && pq.top()<K){
        int a=pq.top();
        pq.pop();
        //a는 가장 맵지 않은 음식
        int b=pq.top()*2;
        pq.pop();
        //b는 두번째로 맵지 않은 음식*2
        pq.push(a+b);
        answer++;
    }
    //pq에 하나 남았는데 그게 K보다 작은 경우 처리
    if(!pq.empty()&&pq.top()<K) return -1;
    else return answer;
}