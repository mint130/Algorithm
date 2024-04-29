#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long prefix1[500002];
long long prefix2[500002];
long long solution(vector<int> sequence) {
    long long ans1 = 0;
    long long ans2 = 0;
    int n = sequence.size();
    vector<int> seq1;
    vector<int> seq2;
    for(int i=0;i<n;i++){
        int num=sequence[i];
        if(i%2==1){
            //seq1에 *-1
            seq1.push_back(num*-1);
            seq2.push_back(num);
        }
        else {
            //seq2에 *-1
            seq2.push_back(num*-1);
            seq1.push_back(num);
        }
    }
    prefix1[0]=seq1[0];
    prefix2[0]=seq2[0];
    for(int i=1;i<n;i++){
        if(prefix1[i-1]+seq1[i]>seq1[i]){
            //i-1까지의 누적합에서 현재 숫자를 더한게 현재 숫자보다 크다면 증가중
            prefix1[i]=prefix1[i-1]+seq1[i];
        }
        else {
            prefix1[i]=seq1[i];
        }
    }
     for(int i=1;i<n;i++){
        if(prefix2[i-1]+seq2[i]>seq2[i]){
            //i-1까지의 누적합에서 현재 숫자를 더한게 현재 숫자보다 크다면 증가중
            prefix2[i]=prefix2[i-1]+seq2[i];
        }
        else {
            prefix2[i]=seq2[i];
        }
    }
    
    ans1=*max_element(prefix1, prefix1+n);
    ans2=*max_element(prefix2, prefix2+n);
    return max(ans1, ans2);
}