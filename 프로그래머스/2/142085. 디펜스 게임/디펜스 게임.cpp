#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq; //오름차순 우선순위 큐
    int i;
    for(i=0;i<enemy.size();i++){
        pq.push(enemy[i]);
        if(pq.size()>k){
            //무적권의 갯수보다 커지면 가장 작은 것부터 n에서 지움
            if(pq.top()>n) return i;
            n=n-pq.top();
            pq.pop();
        }
        
    }
    return enemy.size();
}