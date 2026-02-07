#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> m1; // str1의 부분 문자열
map<string, int> m2; // str2의 부분 문자열
set<string> s;
int solution(string str1, string str2) {
    int answer = 0;
    // 공백이나 숫자, 특수문자가 들어있으면 버림
    for(int i=0;i<str1.length()-1;i++){
        if(!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;
        str1[i]=toupper(str1[i]);
        str1[i+1]=toupper(str1[i+1]);
        string tmp = str1.substr(i, 2);
        m1[tmp]++;
        s.insert(tmp);
    }
    for(int i=0;i<str2.length()-1;i++){
        if(!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;
        str2[i]=toupper(str2[i]);
        str2[i+1]=toupper(str2[i+1]);
        string tmp = str2.substr(i, 2);
        m2[tmp]++;
        s.insert(tmp);
    }
    int u = 0; // 합집합
    int n = 0; // 교집합
    for(auto i:s){
        int cnt1 = m1[i];
        int cnt2 = m2[i];
        u += max(cnt1, cnt2);
        n += min(cnt1, cnt2);
    }

    if(u==0 && n==0) return 65536;
    else {
        return 65536*n/u;
    }

    return answer;
}