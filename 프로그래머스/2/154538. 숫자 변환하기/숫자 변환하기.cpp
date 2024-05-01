#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dist[1000002];
queue<int> q;
int solution(int x, int y, int n) {
    //int answer = -1;
    fill(dist, dist+1000002, -1);
    q.push(x);
    dist[x]=0;
    bool flag=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(cur==y){
            break;
        }
        //cur+n
        if(cur+n<=y && dist[cur+n]==-1){
            dist[cur+n]=dist[cur]+1;
            q.push(cur+n);
        }
        //cur*2
        if(cur*2<=y && dist[cur*2]==-1){
            dist[cur*2]=dist[cur]+1;
            q.push(cur*2);
        }
        //cur*3
        if(cur*3<=y && dist[cur*3]==-1){
            dist[cur*3]=dist[cur]+1;
            q.push(cur*3);
        }
    }
    return dist[y];
}