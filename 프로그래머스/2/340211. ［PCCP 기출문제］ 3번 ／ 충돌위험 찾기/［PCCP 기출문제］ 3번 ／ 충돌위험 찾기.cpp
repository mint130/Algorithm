#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
vector<pair<int, int>> p;
int cnt[101][101];
vector<map<pair<int,int>, int>> path; //path[0][{a, b}]=n -> 0초의 a, b위치에서 로봇갯수 = n개
int answer = 0;
int t = 0;
void move(int st, int en){
    pair<int, int> s = p[st];
    pair<int, int> e = p[en];
  
    
    while(s!=e){
       
        //r먼저
        if(s.first!=e.first) {
            if(s.first<e.first) s.first++;
            else s.first--;
        }
        //c
        else if(s.second!=e.second){
            if(s.second<e.second) s.second++;
            else s.second--;
        }
        t++;
        // 이동한 위치 기록 
        path[t][s]++;
        if(path[t][s]==2) answer++;
    }
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {

    for(int i=0;i<points.size();i++){
        p.push_back({points[i][0]-1, points[i][1]-1});
    }
    int len = routes[0].size();
    path.resize(20001);
    for(int i=0;i<routes.size();i++){
        // 로봇마다 시간은 0부터 시작
        t = 0;
        
        // t = 0의 시작 위치 기록
        int start = routes[i][0] - 1;
        path[0][p[start]]++;

        if(path[0][p[start]] == 2)
            answer++;

        for(int j=0;j<len-1;j++){
            int cur = routes[i][j]-1;
            int nxt = routes[i][j+1]-1;
            move(cur, nxt);
        }
    }
    return answer;
}

