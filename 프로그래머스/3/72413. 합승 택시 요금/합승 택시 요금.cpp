#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dist[201][201];
int answer = 987654321;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=987654321;
        }
    }
    for(int i=0;i<fares.size();i++){
        int a = fares[i][0];
        int b = fares[i][1];
        int c = fares[i][2];
        dist[a][b]=c;
        dist[b][a]=c;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) dist[i][j]=0;
                else{
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
                
            }
        }
    }
    
    int aa = dist[s][a]; // 직통
    int bb = dist[s][b];
    answer = min({aa+bb, answer});
    for(int i=1;i<=n;i++){
        // i가 중간지점 
        if(s!=i && dist[s][i]!=987654321) {
            int d = dist[s][i];
            int aaa = dist[i][a];
            int bbb = dist[i][b];
            answer = min({answer, d+aaa+bbb});
        }
    }
    return answer;
}