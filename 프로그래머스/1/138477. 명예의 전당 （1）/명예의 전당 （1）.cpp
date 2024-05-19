#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    int num=score.size();
    vector<int> temp;
    for(int i=0;i<num;i++){
        temp.push_back(score[i]);
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        if(i<k){
            answer.push_back(temp[temp.size()-1]);
        }
        else {
            answer.push_back(temp[k-1]);
        }
       
    }
    return answer;
}