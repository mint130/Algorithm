#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
bool arr[101][101];
vector<int> v[101];
int bfs(int st, int n){
    set<int> s;
    s.insert(st);
    queue<int> q;
    q.push(st);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto nxt:v[cur]){
            if(!arr[cur][nxt] && s.count(nxt)==0){
                s.insert(nxt);
                q.push(nxt);
            }
        }
    }

    int a = s.size();
    int b = n-a;
    return abs(a-b);
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        arr[a][b]=1;
        arr[b][a]=1;
        
        // arr[a][b]가 1이면 못감
        answer = min(answer, bfs(a, n));
        
        arr[a][b]=0;
        arr[b][a]=0;
    }
    return answer;
}