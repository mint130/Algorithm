#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
map <string, int> dist;
int solution(string begin, string target, vector<string> words) {
    //int answer = 0;

    queue<string> q;
    q.push(begin);
    while(!q.empty()){
        string cur=q.front();
        q.pop();
        if(cur==target){
            return dist[cur];
        }
        for(int i=0;i<words.size();i++){
            int cnt=0;
            string nxt=words[i];
            for(int j=0;j<nxt.length();j++){
                //words가 cur과 다른 부분 찾는 cnt변수
                if(nxt[j]!=cur[j]) cnt++;
            }
            if(cnt==1 && !dist[nxt]){
                q.push(nxt);
                dist[nxt]=dist[cur]+1;    
            }
        }
    }
    return 0;
}