#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> q;
int func(string s){
    cout<<s<<endl;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 4));
    return h*60 + m;
}
string func2(int num){
    int h = num/60;
    int m = num%60;
    
    string hh = (h<10?"0":"")+to_string(h);
    string mm = (m<10?"0":"")+to_string(m);
    
    return hh+":"+mm;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> tt;
    for(int i=0;i<timetable.size();i++){
        int t = func(timetable[i]);
        tt.push_back(t);
    }
    sort(tt.begin(), tt.end());
    for(int i=0;i<tt.size();i++) q.push(tt[i]);
    // 큐에 넣음
    int st = 540;
    int idx = 0; // 현재 idx
    int ans = 0;
    for(int i=0;i<n;i++){
        // 현재 시각
        int cur = st+t*i;
        int cnt = 0; // 이번에 태운 사람 수
        while(tt[idx]<=cur && cnt<m && idx<tt.size()){
            // 도착 시간이 버스 출발 시간보다 빠름, 태운 사람 수가 m보다 작음
            idx++;
            cnt++;
        }
        
        // 마지막 버스
        if(i==n-1){
            if(cnt<m){
                // 태울 수 있음
                ans = cur; // 버스 출발시간에 도착
            }
            else {
                ans = tt[idx-1]-1; // 마지막에 탄 사람보다 1분 빠름
            }
        }
        
    }
    return func2(ans);
}