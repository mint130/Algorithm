#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<char> c;
string solution(string my_string) {
    string my_answer="";
    for(auto i:my_string){
        if(i<'a'){
            i=i+32;
        }
        c.push_back(i);
    }
    sort(c.begin(), c.end());
    for(auto i:c){
        my_answer+=i;
    }
    return my_answer;
}