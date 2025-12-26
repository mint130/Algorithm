#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int func(int left, int right, string &s){
    while(left>=0 && right<s.length()){
        if(s[left]==s[right]){
            --left;
            ++right;
        }
        else break;
    }
    return right-left-1;
}
int solution(string s)
{
    int answer=1;
    for(int i=0;i<s.length()-1;i++){
        // 짝수
        // i = i+1, i-1 = i+2, i-2 = i+3
        answer = max(func(i, i+1, s), answer);
        // 홀수
        // i-1 = i+1, i-2 = i+2 ..
        if(i!=0 && i<s.length()) answer = max(func(i-1, i+1, s), answer);
    }

    return answer;
}