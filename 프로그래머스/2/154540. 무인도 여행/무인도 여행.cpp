#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
bool visited[101][101];
char board[101][101];
vector<int> answer;
int n, m;
void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c]=1;
    int sum=0;
    sum+=board[r][c]-'0';
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny]!='X' && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny]=1;
                sum+=board[nx][ny]-'0';
            }
        }
        
    }
    answer.push_back(sum);
}
vector<int> solution(vector<string> maps) {
    n=maps.size();
    m=maps[0].length();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
board[i][j]=maps[i][j];}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && board[i][j]!='X') {visited[i][j]=1; bfs(i, j);}
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size()==0) answer.push_back(-1);
    return answer;
}