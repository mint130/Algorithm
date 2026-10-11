#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    queue<int> q;
    for(int i=0;i<n;i++){
        int day = ceil((double)(100-progresses[i])/speeds[i]); // 반올림
        q.push(day); //작업이 끝나는날
    }
    while(!q.empty()){
        int d = q.front(); // 배포되어야 하는 날짜
        q.pop();
        int cnt = 1; // 같이 배포되는 수
        while(!q.empty() && q.front()<=d){
            // 더 일찍 끝나면 같이 배포
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}