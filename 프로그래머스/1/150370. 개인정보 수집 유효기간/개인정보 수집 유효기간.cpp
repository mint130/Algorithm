#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int today_y, today_m, today_d; //오늘 날짜

map<char, int> m; //약관의 종류와 유효기간
int find_m(char c){ //종류로 유효기간 찾아서 반환
    auto it=m.find(c);
    if(it!=m.end()) return it->second;
}
void today_string(string today){
    //문자열인 오늘 날짜를 int로 변환하여 각각 today_y, today_m, today_d에 담기
    string y_s, m_s, d_s;
    for(int i=0;i<4;i++){
        y_s+=today[i];
    }
    today_y=stoi(y_s);

    for(int i=5;i<=6;i++){
        m_s+=today[i];
    }
    today_m=stoi(m_s);

    
    for(int i=8;i<=9;i++){
        d_s+=today[i];
    }
    today_d=stoi(d_s);
    
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    //terms A 유효기간(string 유의)
    //privacies는 개인정보 수집 날짜 약관종류(string)
    //answer은 오늘 날짜로 파기해야 할 개인정보 번호 -> privacies의 idx+1을 answer에 넣음
    vector<int> answer;
    
    //단위를 가장 작은 일수로 변환하여 생각하기
    //입력받는 값이 전부 string임을 유의 
    
    today_string(today); //오늘 날짜 구함
    int now=today_y*12*28 + today_m*28 + today_d;
    //날짜를 일수 기준으로 변환: 연도*12*28 + 달*28 + 일
  
    for(int i=0;i<terms.size();i++){
        string s=terms[i];
        char alphabet=s[0];
        string month;
        for(int j=2;j<s.length();j++){
            month+=s[j];
        }
        m[alphabet]=stoi(month)*28;
        //일수 기준 변환하여 저장
    }
    //약간 종류와 유효 기간을 map에 저장
    
    for(int i=0;i<privacies.size();i++){
        string s=privacies[i];

        string y_s, m_s, d_s;
        int yy, mm, dd;
        for(int j=0;j<4;j++){
            y_s+=s[j];
        }
        yy=stoi(y_s);
        //yy

        for(int j=5;j<=6;j++){
            m_s+=s[j];
        }
        mm=stoi(m_s);
        //mm

        for(int j=8;j<=9;j++){
            d_s+=s[j];
        }
        dd=stoi(d_s);
        int day= yy*12*28 + mm*28 + dd;
        //똑같은 방식으로 privacies 배열의 날짜(string)들을 숫자로 바꾸고 일수 기준으로 변환
        
        char alphabet=s[11]; //alphabet은 해당 번호의 약관 종류
        int len=m[alphabet];
        
        //개인정보 수집 일자가 오늘 날짜(now)보다 크면 유효기간이 지나지 않으므로 answer에 추가
        if(day > now) answer.push_back(i+1);
        else {
            //개인정보 수집 일자+유효 기간이 오늘 날짜보다 
            if(day+len<=now) answer.push_back(i+1);    
        }
        
    }
    

 
    return answer;


}