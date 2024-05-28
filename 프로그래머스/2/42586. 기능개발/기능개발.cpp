#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<pair<int, int>> dq;
    int n=progresses.size();
    for(int i=0;i<n;i++){
        dq.push_back({progresses[i], speeds[i]});
    }
    while(!dq.empty()){
        int cnt=0;
        while(dq.front().first>=100){
            dq.pop_front();
            cnt++;
        }
        if(cnt!=0) answer.push_back(cnt);
        for(int i=0;i<dq.size();i++){
            dq[i].first+=dq[i].second;
        }
    }
    return answer;
}