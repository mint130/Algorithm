#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[1002][1002];
int sum[1002][1002];
int n, m;
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    n=board.size();
    m=board[0].size();
    for(int i=0;i<skill.size();i++){
        int t = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        int val = (t==1?degree:-degree);
        arr[r1][c1]-=val;
        arr[r2+1][c1]+=val;
        arr[r1][c2+1]+=val;
        arr[r2+1][c2+1]-=val;
    }
    // 차분 배열의 누적 합 계산
    // 가로
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            arr[i][j]+=arr[i][j-1];
        }
    }
    // 세로
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            arr[i][j]+=arr[i-1][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]+arr[i][j]>0) answer++;
        }
    }
    return answer;
}