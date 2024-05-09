#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
using namespace std;
map<int, int> m; //m[idx]=갯수
string solution(vector<int> food) {
    string answer="";
    //food.size()-1가 칼로리의 최대값
    int cal=food.size()-1;
    for(int i=1;i<=cal;i++){
        m[i]=food[i]/2;
    }
    
    for(int i=1;i<=cal;i++){
        for(int j=0;j<m[i];j++){
            answer+=to_string(i);
        }
    }
    answer+=to_string(0);
    for(int i=cal;i>=1;i--){
        for(int j=0;j<m[i];j++){
            answer+=to_string(i);
        }
        
    }
    return answer;
}