#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<char> v;
string answer = "";
void first(string &str){
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }
    }
    
}
string solution(string new_id) {
    //3자 이상 15자 이하
    //알파벳 소문자, 숫자, -, _, .만 사용
    //.는 처음과 끝에 사용 x, 연속으로 사용할 수 x
    for(int i=0;i<new_id.size();i++){
        char c= new_id[i];
        if(c>='A'&&c<='Z') {
            c=c-'A'+'a';
            v.push_back(c);
        }
        else if(c>='a'&&c<='z' || 
                c>='0' && c<='9' ||
                c=='.' || c=='-' || c=='_')
        {
            v.push_back(c);
        }
    }
    //1단계, 2단계
    for(int i=1;i<v.size();i++){
        if(v[i-1]=='.' && v[i]=='.'){
            v[i-1]=' ';
        }
    }
    v.erase(remove(v.begin(), v.end(), ' '), v.end()); 
    //3단계
    if(v[0]=='.') v.erase(v.begin());
    if(v[v.size()-1]=='.') v.erase(v.begin()+v.size()-1);
    //4단계
    if(v.size()==0) v.push_back('a');
    //5단계
    if(v.size()>=16) v.erase(v.begin()+15, v.end());
    if(v[v.size()-1]=='.') v.erase(v.begin()+v.size()-1);
    //6단계
    if(v.size()<=2){
        char n=v[v.size()-1]; //마지막 문자
        while(v.size()!=3){
            v.push_back(n);
        }
    }
   
    for(int i=0;i<v.size();i++){
        answer+=v[i];
    }
    return answer;
}