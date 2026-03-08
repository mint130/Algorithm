#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, int> m1; 
map<int, int> m2;
int solution(vector<int> topping) {
    int answer = 0;
    for(int i=0;i<topping.size();i++){
        m1[topping[i]]++; // m1에 전체 토핑 종류 저장
    }
    for(int i=0;i<topping.size();i++){
        m1[topping[i]]--;
        m2[topping[i]]++;
        if(m1[topping[i]]==0) m1.erase(topping[i]);
        if(m1.size()==m2.size()) answer++;
    }
    return answer;
}