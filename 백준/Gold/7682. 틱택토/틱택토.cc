#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
char board[3][3];
bool isWin(char c){
    //만약 c가 연속 세개 있으면 이김
    for(int i=0;i<3;i++){
        if(board[i][0]==c && board[i][1]==c && board[i][2]==c) return true;
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==c && board[1][i]==c && board[2][i]==c) return true;
    }
    if(board[0][0]==c && board[1][1]==c && board[2][2]==c) return true;
    if(board[0][2]==c && board[1][1]==c && board[2][0]==c) return true;
    return false;
}

int main() {
    string str="";
    while(1){
        bool isValid = false;
        cin>>str;
        if(str=="end") return 0;
        int x = 0;
        int o = 0; //x와 o의 갯수 
        int empty = 0; //.의 갯수
        for(int i=0;i<9;i++){
            int row=i/3;
            int col=i%3;
            board[row][col]=str[i];
            if(str[i]=='X') x++;
            else if(str[i]=='O') o++;
            else empty++;
        }
        

        bool owin=isWin('O');
        bool xwin=isWin('X');

        if(x==o){
            //o가 이겨야함
            if(owin&&!xwin) isValid=1; //o가 이김
        }
        else if(x==o+1){
            //x가 이기거나 아무도 이기지 못하거나 
            if(xwin&&!owin) isValid=1; //x가 이김
            if(!xwin&&!owin&&empty==0) isValid=1; //무승부
        }
        if(isValid){
            cout<<"valid\n";
        }
        else {
            cout<<"invalid\n";
        }
    
    }

}