#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char board[31][31];
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    // 높이 m, 폭 n
    for(int i=0;i<board.size();i++){
        string s = board[i];
        for(int j=0;j<s.length();j++){
            board[i][j]=s[j];
        }
    }

    vector<pair<int, int>> v; // 이번
    while(1){
        // 상하좌우로 인접한 블록이 하나도 없을 때 까지
        v.clear();
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                // board[i][j], board[i+1][j], board[i][j+1], board[i+1][j+1]
                char a = board[i][j];
                char b = board[i+1][j];
                char c = board[i][j+1];
                char d = board[i+1][j+1];
                if(a=='X'||b=='X'||c=='X'||d=='X') continue;
                if(a==b && b==c && c==d && a==d){
                    cout<<i<<" "<<j<<endl;
                    v.push_back({i, j});
                    v.push_back({i+1, j});
                    v.push_back({i, j+1});
                    v.push_back({i+1, j+1});
                }
            }
        }
        if(v.size()==0){
            // 끝
            return answer;
        }
        else {
            int cnt = 0;
            for(auto i:v){
                int x = i.first;
                int y = i.second;
                if(board[x][y]!='X') {
                    board[x][y]='X';
                    cnt++;
                }
            }
            answer+=cnt;
            queue<char> q;
            // 밑으로 내림
            for(int j=0;j<n;j++){
                for(int i=0;i<m;i++){
                    if(board[i][j]!='X'){
                        q.push(board[i][j]);
                    }
                }
                
                for(int i=0;i<m;i++){
                    if(i>=m-q.size()){
                        board[i][j]=q.front();
                        q.pop();
                    }
                    else board[i][j]='X';
                }   
            }
        }
    }
    return answer;
}