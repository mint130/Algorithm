#include <string>
#include <vector>
#include <iostream>
using namespace std;

int apeach[11];
int ans = -1;
vector<int> answer;

void dfs(int idx, int arrow, vector<int> ryan) {
    if (idx == 11) {
        // 남은 화살 모두 0점 과녁에
        ryan[10] += arrow;

        int ascore = 0, rscore = 0;
        for (int i = 0; i < 11; i++) {
            if (ryan[i] == 0 && apeach[i] == 0) continue;
            if (ryan[i] > apeach[i]) rscore += (10 - i);
            else ascore += (10 - i);
        }

        int diff = rscore - ascore;
    
        if(diff>0 && diff>=ans){
            if(diff==ans){
                // 뒤에 있는 것들이 커야함
                for(int i=10;i>=0;i--){
                    if(ryan[i]!=answer[i]){
                        if(ryan[i]>answer[i]){
                            answer = ryan;
                        }
                        break;   
                    }
                }
            }
            else {
                answer = ryan;
                ans = diff;
            }
        }
        return;
    }

    // idx번째 포기
    dfs(idx + 1, arrow, ryan);

    // idx번째 이기기
    int need = apeach[idx] + 1;
    if (arrow >= need) {
        ryan[idx] = need;
        dfs(idx + 1, arrow - need, ryan);
    }
}

vector<int> solution(int n, vector<int> info) {
    for (int i = 0; i < 11; i++) apeach[i] = info[i];
    vector<int> ryan(11, 0);
    dfs(0, n, ryan);

    if (ans == -1) return {-1};
    return answer;
}
