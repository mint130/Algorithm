#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int answer = 0;
bool used[9];
int sz;
vector<int> v; // 현재 뽑은 idx 번호들
vector<vector<string>> r;
vector<vector<int>> can;
bool uniqueness(){
    // 유일성 충족하는지 -> set
    set<string> s;
    for(int i=0;i<r.size();i++){
        string str = "";
        for(int j=0;j<sz;j++){
            if(used[j]){
                str+=r[i][j];
            }
        }
        // 100music 200math 300computer ..
        s.insert(str);
    }
    if(s.size()==r.size()) {
        // 후보키에 넣음
        can.push_back(v);
        return true;
    }
    else return false;
}
bool minimality() {
    // 최소성 충족하는지 -> 현재 v가 can안에 포함되어 있으면 안됨
    for(auto c:can){
        // vector<int> 1, 2, 3
        bool flag = 1; // 부분집합->1
        for(int key: c){
            if (find(v.begin(), v.end(), key) == v.end()) {
                // key가 v에 없음 -> 부분 집합 아님, flag 0
                flag = 0;
                break;
            }
        }
        if(flag) return false; // 부분집합 맞음 -> 최소성 충족 x
    }
    return true;
    
}
void dfs(int idx, int cnt, int n){
    if(cnt==n){
        if(minimality() && uniqueness()) answer++;
        return;
    }
    for(int i=idx;i<sz;i++){
        if(!used[i]){
            used[i]=1;
            v.push_back(i);
            dfs(i+1, cnt+1, n);
            v.pop_back();
            used[i]=0;
        }
    }
}
int solution(vector<vector<string>> relation) {
    sz = relation[0].size();
    for(int i=0;i<relation.size();i++){
        vector<string> s;
        for(int j=0;j<relation[i].size();j++){
            s.push_back(relation[i][j]);
        }
        r.push_back(s);
    }
    
    for(int i=1;i<=sz;i++){
        dfs(0, 0, i); // 1부터 n개까지 고름
    }
    return answer;
}