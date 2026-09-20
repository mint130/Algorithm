#include <string>
#include <vector>
#include <queue>
using namespace std;
// x+n , x*2, x+3
int dist[1000001];
queue<int> q;
int solution(int x, int y, int n) {
    int answer = 0;
    fill(dist, dist+1000001, -1);
    dist[x]=0;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur==y) return dist[cur];
        if(cur*3<=y && dist[cur*3]==-1) {
            dist[cur*3]=dist[cur]+1;
            q.push(cur*3);
        }
        if(cur*2<=y && dist[cur*2]==-1){
            dist[cur*2]=dist[cur]+1;
            q.push(cur*2);
        }
        if(cur+n<=y && dist[cur+n]==-1){
            dist[cur+n]=dist[cur]+1;
            q.push(cur+n);
        }
        
    }
    return -1;
}