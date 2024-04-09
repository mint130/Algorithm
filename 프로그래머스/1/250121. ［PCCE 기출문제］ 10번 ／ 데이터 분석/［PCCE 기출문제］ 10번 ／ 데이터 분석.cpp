#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int sortnum=-1;

bool cmp (vector<int> &a, vector<int> &b){
    return a[sortnum]<b[sortnum];
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    int n=data.size();
    
    //코드번호, 제조일, 최대수량, 현재 수량
    //ext는 code, date, maximum, remain
    //sort_by는 code, date, maximum, remain
    //data에서 ext 값이 val_ext보다 작은 데이터만 뽑고 sort by 해당 기준으로 오름차순 정렬
    if(sort_by=="code") sortnum=0;
    else if(sort_by=="date") sortnum=1;
    else if(sort_by=="maximum") sortnum=2;
    else sortnum=3;
    
    for(int i=0;i<n;i++){
        int code=data[i][0];
        int date=data[i][1];
        int maximum=data[i][2];
        int remain=data[i][3];
        vector<int> tmp;
        bool flag=0;
        if(ext=="code" && code<val_ext){
             flag=1;
        }
        else if(ext=="date" && date<val_ext){
            flag=1;
        }
        else if(ext=="maximum" && maximum<val_ext){
            flag=1;
        }
        else if(ext=="remain" && remain<val_ext){
             flag=1;
        }
        if(flag==1){
            tmp.push_back(code);
            tmp.push_back(date);
            tmp.push_back(maximum);
            tmp.push_back(remain);
            answer.push_back(tmp);
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}