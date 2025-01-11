#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> a; //철수 토핑 가짓수
map<int, int> b; //동생 토핑 가짓수

int solution(vector<int> topping) {
    int answer = 0;
    
    for(int i=0;i<topping.size();i++){
        //i번째 토핑 동생이 가짐
        b[topping[i]]++;
    }
    for(int i=0;i<topping.size();i++){
        //i번째 토핑을 동생에게서 빼고 철수에게 넣음
        a[topping[i]]++;
        b[topping[i]]--;
        if(b[topping[i]]==0) b.erase(topping[i]); 
        //토핑 갯수가 작아져서 가짓수에서 빠지면 map에서 지워줌(size 함수 쓰기 위해)
        if(a.size()==b.size()) answer++;
    }
    return answer;
}