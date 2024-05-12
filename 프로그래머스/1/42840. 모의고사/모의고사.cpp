#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    //수포자 1번 1,2,3,4,5
    //수포자 2번 2,1,2,3,2,4,2,5,2,1,2,3,..
    //수포자 3번 3,3,1,1,2,2,4,4,5,5,
    vector<int> arr1={1, 2, 3, 4, 5};
    vector<int> arr2={2,1,2,3,2,4,2,5};
    vector<int> arr3={3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<answers.size();i++){
        int num=answers[i];
        if(num==arr1[i%arr1.size()]) cnt1++;
        if(num==arr2[i%arr2.size()]) cnt2++;
        if(num==arr3[i%arr3.size()]) cnt3++;
        
    }

    if(cnt1==max({cnt1, cnt2, cnt3})){
        answer.push_back(1);
    }
    if(cnt2==max({cnt1, cnt2, cnt3})){
        answer.push_back(2);
    }
    if(cnt3==max({cnt1, cnt2, cnt3})) {
        answer.push_back(3);
    }
    return answer;
}