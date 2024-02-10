#include <string>
#include <vector>
#include <iostream>
using namespace std;
int board[102][102];
vector<int> answer;
int r1, c1, r2, c2;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {

    //init
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            board[i][j]=(j+1)+(columns*(i));
        }
    }
    for(int k=0;k<queries.size();k++){
        r1=queries[k][0]-1;
        c1=queries[k][1]-1;
        r2=queries[k][2]-1;
        c2=queries[k][3]-1;
        
        int a=board[r1][c1];
        int minnum=a;
      
        for(int i=r1;i<r2;i++){
           
            board[i][c1]=board[i+1][c1];
            minnum=min(minnum, board[i][c1]);
        }
        for(int i=c1;i<c2;i++){
            board[r2][i]=board[r2][i+1];
            minnum=min(minnum, board[r2][i]);
        }
        for(int i=r2;i>r1;i--){
            board[i][c2]=board[i-1][c2];
            minnum=min(minnum, board[i][c2]);
        }
        for(int i=c2;i>c1;i--){
            board[r1][i]=board[r1][i-1];
            minnum=min(minnum, board[r1][i]);
        }
        board[r1][c1+1]=a;
        answer.push_back(minnum);
        
       
    }
    return answer;
}