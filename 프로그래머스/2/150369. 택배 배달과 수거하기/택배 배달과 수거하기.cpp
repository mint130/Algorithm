#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> D, P;
    int box=0;
    for(auto i: deliveries){
        D.push(i);
    }
    for(auto i:pickups){
        P.push(i);
    }
    
    //가장 먼 집이 배달가거나 수거할 택배가 없으면 제거
    while(!D.empty() && D.top()==0){
        D.pop();
    }
    while(!P.empty() && P.top()==0){
        P.pop();
    }
    //가장 위에 가장 먼 집이 있음
    //둘 다 비었을때 종료
    while(!D.empty() || !P.empty()){
        answer+=max(D.size() *2, P.size()*2);
        //왕복 거리
        box=0;
        while(!D.empty() && box <= cap){
            if(D.top()+box<=cap){
                //D.top의 집에 배달 가능
                box+=D.top();
            }
            else {
                //다시 와야함
                D.top()=D.top()-(cap-box); 
                break;
            }
            D.pop();
        }
        box=0;
        while(!P.empty() && box <= cap){
            if(P.top()+box<=cap){
                box+=P.top();
            }
            else {
                P.top()=P.top()-(cap-box);
                break;
            }
            P.pop();
        }
        
    }
    return answer;
}