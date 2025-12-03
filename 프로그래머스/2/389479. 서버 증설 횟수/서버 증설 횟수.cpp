#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int server[25]; // 현재 서버 수
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for(int i=0;i<players.size();i++){
        int a = players[i]/m;
        // 필요한 서버수 a
        if(server[i]<a){
            int inc = a-server[i]; // 늘릴 서버수
            int cnt = 0;
            while(cnt<k && (i+cnt)<24){
                server[i+cnt]+=inc;
                cnt++;
            }
            answer+=inc;
        }
        
    }
    return answer;
}