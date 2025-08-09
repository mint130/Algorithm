#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dist[201][201];
#define MAX 987654321
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=MAX;
        }
    }
    for(int i=0;i<fares.size();i++){
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2]; 
        dist[c][d]=f;
        dist[d][c]=f;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) dist[i][j]=0;
                if(dist[i][k]==MAX || dist[k][j]==MAX) continue;
                dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);
            }
        }
    }
    answer = dist[s][a]+dist[s][b];
    for(int i=1;i<=n;i++){
        if(s==i) continue;
        if(dist[s][i] ==MAX || dist[i][a]== MAX || dist[i][b]== MAX) continue;
        answer =min(answer, dist[s][i]+dist[i][a]+dist[i][b]);
    }
    return answer;
}