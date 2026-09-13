#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int n;
bool cmp(pair<int, int> p1, pair<int, int> p2){
    // 나가는 순서대로 정렬
    if(p1.second==p2.second) return p1.first>p2.first;
    else return p1.second<p2.second;
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    n = routes.size();
    for(int i=0;i<n;i++){
        v.push_back({routes[i][0], routes[i][1]});
    }
    sort(v.begin(), v.end(), cmp);
    int flag = -30001;
    for(int i=0;i<v.size();i++){
        int a = v[i].first;
        int b = v[i].second;
        if(a>flag || b<flag)
        {
            flag = b;
            answer++;
        }
    }
    return answer;
}