#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if(isalpha(s[0])) s[0]=toupper(s[0]);
    for(int i=1;i<s.length();i++){
       if(isalpha(s[i])){
           if(s[i-1]==' ') s[i]=toupper(s[i]);
           else s[i]=tolower(s[i]);
       }
    }
    return s;
}