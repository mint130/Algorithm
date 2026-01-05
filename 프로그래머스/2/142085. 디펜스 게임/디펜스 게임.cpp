#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
bool used[1000001];

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if(k>=enemy.size()) return enemy.size();
    priority_queue<int, vector<int>, less<>> pq;
    for(int i=0;i<enemy.size();i++){
        n-=enemy[i];
        pq.push(enemy[i]);
        if(n<0){
            if(k>0){
                int num = pq.top();
                n+=num;
                pq.pop();
                k--;
            }
            else {
                return i;
            }
        }
    }
    return enemy.size();
}