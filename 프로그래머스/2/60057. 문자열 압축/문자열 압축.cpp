#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int compression(string s, int len){
    string ans = "";
    
    string prev = s.substr(0, len); // 가장 처음 문자열
    int cnt = 1;
    
    for(int i=len;i<s.length();i+=len){
        
        string tmp = s.substr(i, len); // len만큼 자름
        if(tmp == prev){
            cnt++;
        }
        else {
            // 반복되는 횟수가 1이 아니면
            if(cnt!=1) {
                ans+=to_string(cnt);
            }
            ans += prev;
            prev = tmp;
            cnt = 1;
        }
    }
    // 마지막 따로 추가
    if(cnt!=1) ans+=to_string(cnt);
    ans+=prev;
    
    //cout<<ans<<endl;
    // 문자열 길이
    return ans.size();
}
int solution(string s) {
    int len = s.length();
    int answer = len;
    for(int i=1;i<=len/2;i++){
        // 자르는 갯수 i
        answer = min(answer, compression(s, i));
    }
    return answer;
}