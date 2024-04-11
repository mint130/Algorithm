#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len=t.length();
    int sublen=p.length();
    
    for(int i=0;i<=len-sublen;i++){
        string subs=t.substr(i, sublen);
        if(subs<=p) answer++;
    }
    return answer;
}