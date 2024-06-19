#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int st=0;
    int en=people.size()-1;
    while(st<=en){
        if(people[st]+people[en]<=limit){
            //둘 다 탈 수 있음
            answer++;
            st++;
            en--;
        }
        else {
            answer++;
            en--;
        }
    }
    return answer;
}