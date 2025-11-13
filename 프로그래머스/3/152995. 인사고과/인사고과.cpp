#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v; // 합 저장
vector<pair<int, int>> p;
bool cmp (pair<int, int> p1, pair<int, int> p2){
    // 첫번째는 내림차순 두번째는 오름차순
    if(p1.first!=p2.first){
        return p1.first>p2.first;
    }
    else {
        return p1.second<p2.second;
    }
}
int solution(vector<vector<int>> scores) {
    int inita = scores[0][0];
    int initb = scores[0][1]; // 완호의 점수
    int sum = inita+initb; // 합산 점수
    v.push_back(sum);
    int maxb = 0;
    
    for(int i=1;i<scores.size();i++){
        p.push_back({scores[i][0], scores[i][1]});
    }
    sort(p.begin(), p.end(), cmp);
    for(auto i:p){
        int a = i.first;
        int b = i.second;

        if(inita < a && initb < b){
            // 완호 인센티브 못받음
            return -1;
        }
        if(b < maxb){
            // 인센티브 못받음
            continue;
        }
        else if(b > maxb){
            maxb = b;
        }
        v.push_back(a+b);
    }
    sort(v.begin(), v.end(), greater<>());
    int answer = 1;
    for(int i = 0; i<v.size();i++){
        if(v[i]==sum) break;
        answer++;
    }
    return answer;
}