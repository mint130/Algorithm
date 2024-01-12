#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;


int answer = 0;
int solution(vector<vector<int>> board, vector<int> moves) {
    queue<int>q[32];

    int size = board[0].size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[j][i]!=0){
                q[i+1].push(board[j][i]);
            }            
        }
    }
    
    stack<int> s;
    //큐에서 뽑은 인형이 들어가는 바구니 s
    
    for(int i=0;i<moves.size();i++){
        int num=moves[i]; //num번째 큐에서 인형을 뺀다

        if(!q[num].empty()) {
            int front=q[num].front();
            q[num].pop();
            if(s.empty()) {
                s.push(front); 
            }
            else {
                if(s.top()!=front) {
                s.push(front); //뺀 인형을 바구니에 넣는다
                }
                else{
                //인형이 바구니 위에 있는 것과 일치하면 
                s.pop();
                answer=answer+2; //인형은 두개 터짐
                }

            }
            
        }
    }
   

    return answer;
}