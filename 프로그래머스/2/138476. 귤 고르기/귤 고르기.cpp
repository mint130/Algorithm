#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    //서로 다른 종류의 원소 최소값
    //k는 한 종류에 담으려는 귤의 갯수
    //vector<int> cnt[10000001];
    for(int i=0;i<tangerine.size();i++){
        int size=tangerine[i];
        //cnt[size]++;
        m[size]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for(auto i:m){
        //cout<<i.first<<" "<<i.second<<endl;
        pq.push({i.second, i.first});
    }
    int cnt=0; //종류
    while(!pq.empty()){
        if(k<=0){
            answer=cnt;
            break;
        }
        k=k-pq.top().first; //갯수
        cnt++;
        pq.pop();
    }

    return cnt;
}