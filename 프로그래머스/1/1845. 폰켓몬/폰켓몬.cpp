#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
set<int> s;
int solution(vector<int> nums)
{
    for(auto i:nums){
        s.insert(i);
    }
    if(s.size()<nums.size()/2) return s.size();
    else return nums.size()/2;
    
}