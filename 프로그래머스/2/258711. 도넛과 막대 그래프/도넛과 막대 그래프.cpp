#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visited[1000002];
vector<int> v[1000002];
int indegree[1000002];
int outdegree[1000002];
int st=0;
vector<int> answer(4);
void dfs(int cur){
    if(visited[cur]) {answer[1]++; return;} //원점으로 다시 돌아오면 도넛 모양 그래프
    if(outdegree[cur]>=2) {answer[3]++; return;} //8자 모양 그래프
    if(outdegree[cur]==0) {answer[2]++; return;}
    visited[cur]=1;    
    for(auto nxt:v[cur]){
        dfs(nxt);
    }
}

vector<int> solution(vector<vector<int>> edges) {

    int n=0; //갯수
    for(int i=0;i<edges.size();i++){
        int a=edges[i][0];
        int b=edges[i][1];
        if(a>b) {
            n=max(n, a);
        }
        else {
            n=max(n, b);
        }
        v[a].push_back(b);
        //a->b
        indegree[b]++;
        outdegree[a]++;
    } 
    //indegree는 0이고 outdegree만 존재하는 점이 새로 만든 정점
    for(int i=1;i<=n;i++){
        if(indegree[i]==0 && outdegree[i]>=2){
            answer[0]=i;
            st=i;
            break;
        }
    }
    
    for(auto i:v[st]){
        dfs(i);    
    }
   
    return answer;
}