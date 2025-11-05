#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
char board[51][51];
int dist[51][51];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int n, m;
void func1(char c){
    vector<pair<int, int>> v; // 나중에 출고 처리
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=-1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=0 && j!=0 && i!=n-1 && j!=m-1) continue;
            if(board[i][j]==c) {
                // 외곽에서 발견
                v.push_back({i, j});
            }
            else if(board[i][j]=='0'){
                // 비었음
                queue<pair<int, int>> q;    
                q.push({i, j});
                dist[i][j]=0;
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int d=0;d<4;d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny]==c && dist[nx][ny]==-1){
                            // 빼야함
                            v.push_back({nx, ny});
                            dist[nx][ny]=dist[x][y]+1; // 방문
                        }
                        if(board[nx][ny]=='0' && dist[nx][ny]==-1){
                            // 빈 공간이면 계속 탐색
                            q.push({nx, ny});
                            dist[nx][ny]=dist[x][y]+1;
                        }
                    }
                }
            }
        }
    }
    // 없앰
    for(auto i:v){
        int x = i.first;
        int y = i.second;
        board[x][y]='0';
    }
}
void func2(char c){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==c) board[i][j]='0';
        }
    }
}
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size();
    m = storage[0].length();
    for(int i=0;i<storage.size();i++){
        for(int j=0;j<storage[i].length();j++){
            board[i][j]=storage[i][j];
        }
    }
    for(int i=0;i<requests.size();i++){
        char c = requests[i][0];
        if(requests[i].length()==2){
            // 있는 것 다 없애기
            func2(c);
        }
        else {
            // 외곽 따라서 없앰
            func1(c);
        }       
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<board[i][j]<<" ";
            if(board[i][j]!='0') answer++;
        }
        //cout<<endl;
    }
    return answer;
}