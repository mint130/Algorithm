#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<int, int>> v;
bool cmp (pair<int, int> p1, pair<int, int> p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    else return p1.second<p2.second;
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    for(int i=0;i<routes.size();i++){
        v.push_back({routes[i][0], routes[i][1]});
    }
    sort(v.begin(), v.end(), cmp);
    int flag = -30001;
    for(int i=0;i<v.size();i++){
        int a = v[i].first;
        int b = v[i].second;
        if(flag<a || flag>b){
            flag = b;
            answer++;
        }
        //cout<<a<<" "<<b<<endl;
        
    }
    return answer;
}