#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0;i<phone_book.size();i++) m[phone_book[i]]++;
    for(int i=0;i<phone_book.size();i++){
        for(int j=1;j<phone_book[i].length();j++){
            if(m[phone_book[i].substr(0,j)]) return false;
        }
        
    }
    return answer;
}