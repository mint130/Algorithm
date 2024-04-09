#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int s=0;
    int e=0;
    int len=sequence.size(); //길이
    int sum=sequence[0];
    int sublen=len;
    pair<int, int> result={0, len-1}; //나올 수 있는 결과 중 가장 긴 값
    
    while(e<len && s<=e){
       
        if(sum==k){
            //구간의 합이 k와 일치하면 현재 부분 수열의 길이가 더 짧은지 확인
            if(e-s+1<sublen){
                sublen=e-s+1;
                result={s,e};
            } else if(e-s+1==sublen){
                //같다면 시작 인덱스가 더 앞쪽인지 확인
                if(s<result.first){
                    result={s,e};
                }
            }
            //sum에서 sequence[s]를 빼주고 s를 증가
            sum-=sequence[s];
            s++;
        }
        
        //구간의 합이 k보다 작으면 e를 증가하고 sum에 sequence[e]를 더함 
        if(sum<k){
            e++;
            sum+=sequence[e];
                        
        }
        //구간의 합이 k보다 크면 sum에서 sequence[s]를 빼주고 s를 증가
         if(sum>k){
            sum-=sequence[s];
            s++;
        }
         
    }
    answer.push_back(result.first);
    answer.push_back(result.second);
    return answer;
}