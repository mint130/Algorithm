#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <queue>
using namespace std;
char board[6][6][6];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int cx[4]={1, 1, -1, -1};
int cy[4]={1, -1, 1, -1};
vector<pair<int, int>> v[6];
bool injection(int i, int x, int y) {
    // 인접한지
    for(int d=0;d<4;d++){
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(nx<0||nx>=5||ny<0||ny>=5) continue;
        if(board[i][nx][ny]=='P'){
            return true;
        }
    }
    return false;
}
bool cross(int i, int x, int y){
    for(int d=0;d<4;d++){
        int nx = x+cx[d];
        int ny = y+cy[d];
        if(nx<0||nx>=5||ny<0||ny>=5) continue;
        if(board[i][nx][ny]=='P'){
            if(board[i][nx][y]=='O' || board[i][x][ny]=='O') return true;
        }
    }
    return false;
}
bool two(int i, int x, int y){
    for(int d=0;d<4;d++){
        int nnx = x+dx[d]*2;
        int nny = y+dy[d]*2;
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(nnx<0||nnx>=5||nny<0||nny>=5) continue;
        if(board[i][nnx][nny]=='P'){
            if(board[i][nx][ny]=='O') {
                // 사이에 빈책상
                return true;
            }
        }
    }
    return false;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string s = places[i][j];
            for(int k=0;k<5;k++){
                board[i][j][k]=s[k];
                if(board[i][j][k]=='P') v[i].push_back({j, k});
            }
        }
    }
    for(int i=0;i<5;i++){
        bool flag = 1;
        
        for(auto cur:v[i]){
            int x = cur.first;
            int y = cur.second; // 응시자 자리
            if(injection(i, x, y) || cross(i, x, y) || two(i, x, y)) {
                flag = 0;
                break;
            }
            
        }
        answer.push_back(flag);
    }
    
    return answer;
}