#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    stringstream ss(s);
    string num;
    while(getline(ss, num, ' ')){
        v.push_back(stoi(num));
    }
    sort(v.begin(), v.end());
    answer=to_string(v[0])+" "+to_string(v[v.size()-1]);
    return answer;
}