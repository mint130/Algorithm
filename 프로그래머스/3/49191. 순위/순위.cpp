#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[101][101]; // [a][b]=1 이김 [a][b]=-1 짐

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++){
        int a = results[i][0];
        int b = results[i][1];
        arr[a][b]=1;
        arr[b][a]=-1;
    }
   
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][k]==1 && arr[k][j]==1){
                    arr[i][j]=1;
                    arr[j][i]=-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int num = 0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(arr[i][j]!=0) num++;
        }
        if(num==n-1) answer++;
    }
    return answer;
}