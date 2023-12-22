#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue <int> pq;
    queue<pair<int, int>> q;
    //알고 싶은 것 : priorities[location]이 몇 번째로 실행되는지
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i}); //중요도, 인덱스를 함께 넣는다
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int idx=q.front().second;
        int value=q.front().first;
        q.pop();
        //int priority=pq.front(); //우선순위
        if(value==pq.top()) {
            pq.pop();
            if(idx==location) {
                return answer;
            }
            answer++;
        }
        else {
            q.push({value, idx});
        }
    }
}