#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int>> v;
int t(string s){
    string tmp = s.substr(0, 2);
    int h = stoi(tmp);
    string tmp2 = s.substr(3, 2);
    int m = stoi(tmp2);
    return h*60+m;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(int i=0;i<book_time.size();i++){
        string st = book_time[i][0];
        string en = book_time[i][1];
        v.push_back({t(st), t(en)});
    }
    sort(v.begin(), v.end()); // 시작시간 순으로 정렬
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;// 끝나는 시간 오름차순 
    for(auto i:v){
        int st = i.first; // 시작 시간
        int en = i.second; // 끝나는 시간
        if(pq.empty()){
            pq.push({en, st});
            answer++;
        }
        else {
            // 제일 먼저 끝나는 강의실이랑 비교
            int room = pq.top().first;
            if(st>=room+10){
                // 제일 먼저 끝나는 강의실 +10보다 현재 강의실 시작 시간이 늦으면 그 강의실 쓸 수 있음
                pq.pop();
                pq.push({en, st});
            }
            else {
                // 강의실 추가 
                pq.push({en, st});
                answer++;
            }
        }
    }
    return answer;
}