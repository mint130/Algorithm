#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> answer;
void lottorank(int n){
    if(n<=1) answer.push_back(6);
    else {
      answer.push_back(7-n);
    }
   
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    //lottos가 구매한 로또 번호, win_nums가 당첨 번호
    //lottos가 0이면 알아볼 수 없는 숫자(여러개 가능)
    int lownum=0;
    //0 제외하고 lottos와 win_nums가 일치하는 갯수
    int highnum=0;
    //이미 맞춘 것 제외, 남은 수들이 lottos의 0 갯수보다 같거나 크다: lownum+0의 갯수
    //남은 수들이 lottos의 0 갯수보다 작다: lownum+win_nums 남은 갯수
    
    sort(lottos.begin(), lottos.end());
    int zero=0; //0의 갯수
    
    for(auto x: lottos){
        if(x==0) zero++;
        auto it=find(win_nums.begin(), win_nums.end(), x);
        if(it!=win_nums.end()) {
            win_nums.erase(it);
            lownum++;
        }
    }
    
    int size=win_nums.size(); //맞추고 남은 수 갯수
    if(size>=zero) highnum=lownum+zero;
    else highnum=lownum+size;
   
    lottorank(highnum);
    lottorank(lownum);
    
    return answer;
}