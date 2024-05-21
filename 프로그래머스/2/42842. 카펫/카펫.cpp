#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int sum=brown+yellow;
    //width*height이 sum이 될 수 있는 경우
    for(int h=1;h<=sqrt(sum);h++){
        for(int w=sum;w>=sqrt(sum);w--){
            if(w*h==sum){
                if(w*2+(h-2)*2==brown) {
                    answer[0]=w;
                    answer[1]=h;
                    break;
                }
            }
        }
        
    }
    //brown=width*2 + (height-2)*2
    return answer;
}