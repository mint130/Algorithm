#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<string, int> idx; //idx["muzi"]=0
int arr[52][52]; //선물 표
int give[52]; //idx가 준 선물
int take[52]; //idx가 받은 선물
int score[52]; //선물 지수
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int num=friends.size();
    //fill(arr[0], arr[52], -1); //초기화
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<friends.size();i++){
        idx[friends[i]]=i;
        //idx 넣음
    }
    for(int i=0;i<gifts.size();i++){
        string s=gifts[i];
        istringstream ss(s); //istringstream 변수 ss에 문자열 s를 넣어 초기화
        string a;
        string b;
        ss.str(); //공백을 기준으로 분리
        ss>>a>>b; //문자열 분리해서 선물 준 친구 a, 선물 받은 친구 b
        //cout<<a<<" "<<b<<endl;
        int r=idx[a]; //a의 idx
        int c=idx[b]; //b의 idx
        arr[r][c]++; //r이 주고 c가 받은 선물의 갯수추가
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //준 선물 구하기
    for(int i=0;i<num;i++){
        int sum=0;
        for(int j=0;j<num;j++){
            sum+=arr[i][j];
        }
        give[i]=sum;
    }
    //받은 선물 구하기
    for(int j=0;j<num;j++){
        int sum=0;
        for(int i=0;i<num;i++){
            sum+=arr[i][j];
        }
        take[j]=sum;
    }
    //선물 지수 구하기
    for(int i=0;i<num;i++){
        score[i]=give[i]-take[i];
    }
    
    for(int i=0;i<num;i++){
        int present=0;
        for(int j=0;j<num;j++){
            if(i!=j){
                //arr[i][j]와 arr[j][i]를 비교 
                if(arr[i][j]>arr[j][i]) present++;
                    //더 줬으면 받는 선물 ++ 
                else if (arr[i][j]==arr[j][i]){
                    //똑같이 주고 받았으면 선물지수와 비교
                    if(score[i]>score[j]) present++;
                }
            }
        }
        answer=max(present, answer);
    }
    return answer;
}