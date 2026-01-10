#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int n;
int dist[51][51];
bool used[2501];
vector<pair<int, int>> v[2501];
vector<pair<int, int>> b[2501]; // 빈것 갯수
int cnt = 0; //퍼즐 조각의 갯수
int blank = 0; // 빈 것의 갯수
void bfs(int r, int c, vector<vector<int>> &board, bool flag){
    // flag 1: 테이블
    // flag 0: 게임보드
    queue<pair<int, int>> q;
    q.push({r, c});
    dist[r][c]=1;
    if(flag) v[cnt].push_back({r, c});
    else b[blank].push_back({r, c});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(flag && board[nx][ny] && dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx, ny});
                v[cnt].push_back({nx, ny});
            }
            else if(!flag && !board[nx][ny] && dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx, ny});
                b[blank].push_back({nx, ny});
            }
        }
    }
}
vector<pair<int, int>> r(vector<pair<int, int>> cur){
    // 90도 회전 x, y -> y, -x
    vector<pair<int, int>> res;
    for(auto i:cur){
        res.push_back({i.second, -i.first});
    }
    int x = 51;
    int y = 51;
    for(auto i:res){
        x = min(x, i.first);
        y = min(y, i.second);
    }
    for(int i=0;i<res.size();i++){
        res[i].first-=x;
        res[i].second-=y;
    }
    sort(res.begin(), res.end());
    return res;
}
bool check(int idx, int jdx){
    // idx번째 b와 jdx번째 v가 일치하는지
    if(b[idx].size() != v[jdx].size()) return false;
    vector<pair<int, int>> cur = v[jdx];
    for(int i=0;i<4;i++){
        if(b[idx]==cur) return true;
        cur = r(cur);
    }
    return false;
}
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=-1;
        }
    }
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    n = table.size();
    init();
    // table 블럭 추출
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j] && dist[i][j]==-1){
                cnt++;
                bfs(i, j, table, 1);
            }
        }
    }
    // dist 재활용
    init();
    // game_board 블럭 추출
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!game_board[i][j] && dist[i][j]==-1){
                blank++;
                bfs(i, j, game_board, 0);
            }
        }
    }
    
    for(int i=1;i<=cnt;i++){
        // table에 있던 블록들 0, 0에 가깝게 맞춤
        int x = 51;
        int y = 51;

        for(auto nxt:v[i]){
            x = min(x, nxt.first);
            y = min(y, nxt.second);
        }
        for(int j=0;j<v[i].size();j++){
            v[i][j].first -= x;
            v[i][j].second -= y;
        }
        sort(v[i].begin(), v[i].end());
    }
    for(int i=1;i<=blank;i++){
        // game board 빈 블록들 0, 0에 가깝게 맞춤
        int x = 51;
        int y = 51;

        for(auto nxt:b[i]){
            x = min(x, nxt.first);
            y = min(y, nxt.second);
        }
        for(int j=0;j<b[i].size();j++){
            b[i][j].first -= x;
            b[i][j].second -= y;
        }
        sort(b[i].begin(), b[i].end());
    }
    for(int i=1;i<=blank;i++){
        // b[i]번째, v[j]번째 비교
        for(int j=1;j<=cnt;j++){
            if(used[j]) continue; // 한번 쓴 퍼즐은 다시 안 씀
            if(check(i, j)) {
                answer+=b[i].size();
                used[j]=1;
                break;
            };
        }
    }
    return answer;

}