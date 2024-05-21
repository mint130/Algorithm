#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    int cnt=0;
    int zero=0;
    //0 제거, 길이를 2진법으로 변환
    while(s!="1"){
        cnt++;
        string temp=""; //1만 있는 문자열
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') temp+='1';
            else zero++;
        }
        s="";
        int n=temp.length(); //길이
        while(n>0){
            s+=to_string(n%2);   
            n=n/2;
        }
        
        
    }
    answer[0]=cnt;
    answer[1]=zero;
    return answer;
}