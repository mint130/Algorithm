#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
priority_queue<int> pq;
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    //k가 점수
    //m이 들어가는 사과의 수
    for(auto i:score){
        pq.push(i);
    }

    while(!pq.empty()){
        if(pq.size()<m){
            //pq에 남은 갯수가 m보다 작으면 버림
            return answer;
        }
        int boxScore=0; 
        int boxMin=987654321;
        for(int i=0;i<m;i++){
            //m개의 사과 채움
            boxMin=min(boxMin, pq.top());
            //최저 사과 점수 boxMin
            pq.pop();
        }
        boxScore=m*boxMin; //한 상자의 점수
        answer+=boxScore;
    }
    return answer;
}