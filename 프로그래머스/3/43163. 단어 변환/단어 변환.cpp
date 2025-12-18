#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<string, int> dist;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<string> q;
    for(int i=0;i<words.size();i++){
        dist[words[i]]=-1;
    }
    dist[begin]=0;
    q.push(begin);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        
        for(int i=0;i<words.size();i++){
            string nxt = words[i];
            if(dist[nxt]==-1){
                // nxt가 cur이랑 한 글자 차이만 나는지
                int cnt = 0;
                for(int j=0;j<nxt.length();j++){
                    if(cur[j]!=nxt[j]) {
                        cnt++;
                    }
                }
                if(cnt==1){
                    dist[nxt]=dist[cur]+1;
                    q.push(nxt);
                }
            }
            
        }
    }
    return dist[target]==-1?0:dist[target];
}