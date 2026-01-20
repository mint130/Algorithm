#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
map<char, int> m;
int answer =0;
char name[8]={'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
bool used[8];
vector<pair<int, pair<int, int>>> e; // 가능한 간격 넣음
vector<pair<int, pair<int, int>>> u; // num보다 간격 커야함
vector<pair<int, pair<int, int>>> d; // num보다 간격 작야야함
bool valid(vector<int> v){
    for(int i=0;i<e.size();i++){
        int num = e[i].first;
        int a = e[i].second.first;
        int b = e[i].second.second;
        int idx = find(v.begin(), v.end(), a)-v.begin();
        int jdx = find(v.begin(), v.end(), b)-v.begin();
        if(abs(idx-jdx)!=(num+1)) return false;
    }
    for(int i=0;i<u.size();i++){
        int num = u[i].first;
        int a = u[i].second.first;
        int b = u[i].second.second;
        int idx = find(v.begin(), v.end(), a)-v.begin();
        int jdx = find(v.begin(), v.end(), b)-v.begin();
        if(abs(idx-jdx)<=(num+1)) return false;
    }
    for(int i=0;i<d.size();i++){
        int num = d[i].first;
        int a = d[i].second.first;
        int b = d[i].second.second;
        int idx = find(v.begin(), v.end(), a)-v.begin();
        int jdx = find(v.begin(), v.end(), b)-v.begin();
        if(abs(idx-jdx)>=(num+1)) return false;
    }
    return true;
}
void dfs(int cur, vector<int> v){
    if(cur==8){
        if(valid(v)){
            answer++;
        }
        return;
    }
    
    for(int i=0;i<8;i++){
        if(used[i]) continue;
        used[i]=1;
        v.push_back(i);
        dfs(cur+1, v);
        v.pop_back();
        used[i]=0;
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    memset(used, false, sizeof(used));
    e.clear();
    u.clear();
    d.clear();
    m.clear();
    for(int i=0;i<8;i++){
        m[name[i]]=i;
    }
    for(string s:data){
        char c1 = s[0];
        char c2 = s[2];
        if(c2>c1){
            c1=s[2];
            c2=s[0];
        }
        // c1이 더빠름
        char op = s[3];
        int num = s[4]-'0';
        int a = m[c1];
        int b = m[c2];
        if(op=='='){
            e.push_back({num, {a, b}});
        }
        else if(op=='<'){
            d.push_back({num, {a, b}});
        }
        else if(op=='>'){
            u.push_back({num, {a, b}});
        }
    }
    sort(e.begin(), e.end());
    sort(d.begin(), d.end());
    sort(u.begin(), u.end());
    vector<int> v;
    dfs(0, v);
    return answer;
}