#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
stack<int> s;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    reverse(numbers.begin(), numbers.end());
    for(int i=0;i<numbers.size();i++){
        while(!s.empty()){
            if(s.top()>numbers[i]){
                answer.push_back(s.top());
                break;
            }
            s.pop();
        }
        if(s.empty()){
            answer.push_back(-1);
        }
        s.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}