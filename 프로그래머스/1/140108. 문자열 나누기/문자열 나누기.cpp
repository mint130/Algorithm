#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int i=0;
    while(i<s.length()){
        char c=s[i];
        int cnt1=1;
        int cnt2=0;
        int j=i+1;
        while(cnt1!=cnt2 && j<s.length()){
            if(s[j]!=c){
                cnt2++;
                j++;
            }
            else{
                cnt1++;
                j++;
            }
        }
        i=j;
        answer++;
    }
    return answer;
}