#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(int a, int b)
{
    string s1=to_string(a);
    string s2=to_string(b);
   
    return s1+s2>s2+s1;
   
   
}
string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    if(numbers[0]==0) {return "0";}
    else
    {
        
         string answer = "";
    for(int i=0;i<numbers.size();i++)
    {
        //cout<<numbers[i];
        string s=to_string(numbers[i]);
        answer=answer+s;
    }
    return answer;
    }
   
    
    //return answer;
}