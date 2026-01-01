#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string s = "0123456789ABCDEF";
string ton(int n, int num){
    // 진법 n, 숫자 num
    string res = "";
    if(num==0) return "0";
    while(num){
        res = s[num%n] +res;
        num/=n;
    }
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string ans = "";
    int num = 0;
    while(num<=t*m){
        ans+=ton(n, num);
        num++;
    }
    int idx = 0;
    int cnt = 0;
    while(1){
        if(cnt==t){
            // t개 다 채움
            return answer;
        }
        answer+=ans[idx+(p-1)]; // m개씩 건너뛰면서 p-1번째
        idx+=m; // m개씩 건너뜀
        cnt++; // 채운 갯수
    }
    return answer;
}