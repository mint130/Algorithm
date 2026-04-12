#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto i:numbers){
        if(i%2==0) {
            // 짝수는 +1한것
            answer.push_back(i+1);
        }
        else {
            //홀수는 01 찾아서 그부분 10으로 바꿔줌
            long long num = 1;
            while(1) {
                if((i&num)==0) {
                    //0의 위치 찾음
                    break;
                }
                num*=2;
            }
            answer.push_back(i+num-(num>>1));
        }
    }
    return answer;
}