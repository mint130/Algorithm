#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[5002][2];
bool isused[5002];
int answer = 0;

void dfs(int k, int dungeon){
    //dungeon은 현재까지 돈 던전의 갯수
    answer=max(answer, dungeon);
    if(k<=0){
        return;
    }
    for(int i=0;i<n;i++){
        if(!isused[i] && k>=d[i][0]){
            isused[i]=1;
            //k가 i번째의 최소 피로도보다 크거나 같아야 함
            //k에서 i번째의 소모 피로도 뺌
            dfs(k-d[i][1], dungeon+1);
            isused[i]=0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    n=dungeons.size();
    //최소 필요 피로도 이상이어야 하고, 탐험 후에는 소모 피로도만큼 -
    //유저가 탐험할 수 있는 최대 던전수
    //최소 필요 피로도가 높은 곳부터 탐색
    sort(dungeons.rbegin(), dungeons.rend());
    for(int i=0;i<n;i++){
        d[i][0]=dungeons[i][0];
        d[i][1]=dungeons[i][1];
    }
    dfs(k, 0);
    return answer;
}