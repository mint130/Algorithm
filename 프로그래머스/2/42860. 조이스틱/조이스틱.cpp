#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;

    for(int i=0;i<name.length();i++){
        char c = name[i];
        answer += min(c-'A', 'Z'-c+1);
    }
    int len = name.length();
    int move = len - 1; // 처음부터 끝까지 이동
    for(int i=0;i<name.length();i++){
        int nxt = i+1;
        while(nxt<name.length() && name[nxt]=='A'){
            // A 건너뛰기 위해 A가 끝나는 지점 찾음
            nxt++;
        }
        move = min(move, i+i+len-nxt);
        move = min(move, (len-nxt)*2+i);
    }
    return answer+move;
}