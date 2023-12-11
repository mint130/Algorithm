#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[8][8]={0,};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n=board[0].size();
    //board[h][w]와 이웃한 칸들 중 같은 색으로 칠해져있는 칸의 개수 return
    string s=board[h][w]; //s는 board[h][w]의 색
    //cout<<s<<endl;
    for(int i=0;i<4;i++){
        int nx=dx[i]+h;
        int ny=dy[i]+w;
        //nx와 ny는 다음 좌표
        if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]==0){
            //cout<<"nx ny "<<nx<<" "<<ny<<endl;
            if(board[nx][ny]==s){
                answer++;
            }
            visited[nx][ny]=1;            
        }
    }
    return answer;
    
    //BFS?
    
}