#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
vector<pair<pair<int, int>, int>> v; // {{시작 시간, 길이}, 순서}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    for(int i=0;i<jobs.size();i++){
        v.push_back({{jobs[i][0], jobs[i][1]}, i});
    }
    sort(v.begin(), v.end()); // 시작 시간이 빠른 순 정렬
    // {{소요시간, 요청시각},번호}
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
    int cnt = 0; // 완료된 작업 갯수
    int idx = 0; // 현재 작업 순서
    int t = 0; // 현재 시각
    while(cnt<jobs.size()){
        // 대기큐로 이동
        while(idx<jobs.size() && v[idx].first.first<=t){
            pq.push({{v[idx].first.second, v[idx].first.first}, v[idx].second});
            idx++;
        }
        if(pq.empty()){
            // 지금 대기큐에 없음 -> 시간을 요청 시간으로 이동
            t = v[idx].first.first;
            continue;
        }
        int st = pq.top().first.second;
        int len = pq.top().first.first;
        pq.pop();
        t+=len; // 현재 시각 변경
        answer += (t-st);
        cnt++;
        
    }
    return answer/jobs.size();
}