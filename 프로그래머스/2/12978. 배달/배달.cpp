#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dist[51][51];
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dist[i][j]=987654321;
            if(i==j) dist[i][j]=0;
        }
    }
    for(int i=0;i<road.size();i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        if(c<dist[a][b]){
            dist[a][b]=c;
            dist[b][a]=c;
        }
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);
                dist[j][i]=dist[i][j];
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dist[1][i]<=K) answer++;
    }

    return answer;
}