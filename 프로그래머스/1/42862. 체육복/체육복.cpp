#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool lstudent[32]; 
bool rstudent[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer=0;
    answer=n-lost.size(); //현재 체육복 없는 학생 수

    for(int i=0;i<lost.size();i++){
        int idx=lost[i];
        lstudent[idx]=1;
    }
    for(int i=0;i<reserve.size();i++){
        int idx=reserve[i];
        rstudent[idx]=1;
        if(lstudent[idx]) {
            rstudent[idx]=0;
            lstudent[idx]=0;
            answer++;
        }
    }
    for(int i=1;i<=n;i++){
        if(lstudent[i]){
            if(rstudent[i-1]){
                rstudent[i-1]=0;
                answer++;
            }
            else if(rstudent[i+1]){
                rstudent[i+1]=0;
                answer++;
            }
        }
        //i번째 학생이 체육복을 잃어버렸다면 rstudent[i-1], rstudent[i+1]이 1인지 확인
        
    }
    return answer;
}