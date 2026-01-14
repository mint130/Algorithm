#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool top[101][101]; // 기둥
bool right[101][101]; // 보
int sz = 0;
// 기둥 -> board[x][y-1]이 기둥, board[x][y]가 보, board[x-1][y]가 보, board[x][0]
// 보 -> board[x][y-1]이 기둥, board[x+1][y-1]이 기둥, board[x-1][y] && board[x+1][y]이 보
bool canTop(int x, int y){
    if(y==0) return true;
    if(top[x][y-1]) return true;
    if(right[x][y]) return true;
    if(x>0 && right[x-1][y]) return true;
    return false;
}
bool canRight(int x, int y){
    if(top[x][y-1]) return true;
    if(x<sz && top[x+1][y-1]) return true;
    if(x>0 && x<sz && right[x-1][y] && right[x+1][y]) return true;
    return false;
    
}
void build(int x, int y, int num){
    if(num==0){
        // 기둥
        if(canTop(x, y)){
            top[x][y]=1;
        }
    }
    else {
        // 보
        if(canRight(x, y)){
            right[x][y]=1;
        }
    }
}
void remove(int x, int y, int num){
    if(num==0){
        // 기둥
        top[x][y]=0;
    }
    else {
        // 보
        right[x][y]=0;
    }
    
    // 삭제할 수 있는지 확인
    for(int i=max(0, x-1);i<= min(sz, x+1);i++){
        for(int j=max(0, y);j<=min(sz, y+1);j++){
            if(top[i][j] && !canTop(i, j)){
                // 복구
                if(num==0){
                    top[x][y]=1;
                }
                else right[x][y]=1;
                return;
            }
            if(right[i][j] && !canRight(i, j)){
                if(num==0){
                    top[x][y]=1;
                }
                else right[x][y]=1;
                return;
            }
        }
    }
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    sz = n;
    // 기둥은 바닥 위, 보의 한쪽 끝 부분 위, 다른 기둥 위
    // 보는 한쪽 끝 부분이 기둥 위, 양쪽 끝 부분이 다른 보와 동시에 연결
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2]; // 0은 기둥 1은 보
        int b = build_frame[i][3]; // 0은 삭제 1은 설치
        
        if(b==0){
            // 삭제
            remove(x, y, a);
        }
        else {
            // 설치
            build(x, y, a);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(top[i][j]) answer.push_back({i, j, 0});
            if(right[i][j]) answer.push_back({i, j, 1});
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}