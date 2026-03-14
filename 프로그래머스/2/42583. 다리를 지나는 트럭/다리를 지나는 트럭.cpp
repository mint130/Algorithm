#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q; // 다리 건너는 중
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total = 0; // 올라와 있는 차 무게
    int idx = 0;
    while(1){
        if(idx==truck_weights.size()) {
            // 마지막 트럭이 건넘 
            answer+=bridge_length; // 마지막 다리 건너는 시간
            break;
        }
        answer++;
        int t = truck_weights[idx];
        
        if(q.size()==bridge_length) {
            // 다 올라옴 -> 다리에서 보내야함
            total-=q.front();
            q.pop();
        }
        // 트럭에 차 올림
        if(t+total<=weight) {
            total+=t;
            idx++;
            q.push(t);
        }
        else q.push(0); // 다리에 다음 트럭 못올리는 경우 무한루프 발생 -> 시간이 감
        
    }
    return answer;
}