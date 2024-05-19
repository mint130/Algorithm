#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    int left, top=52;
    int right, down=0;
    vector<int> r;
    vector<int> c;
    int len=wallpaper[0].length();
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<len;j++){
            if(wallpaper[i][j]=='#'){
                r.push_back(i);
                c.push_back(j);
            }
        }
    }
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    answer[0]=r[0];
    answer[1]=c[0];
    answer[2]=r[r.size()-1]+1;
    answer[3]=c[c.size()-1]+1;

    return answer;
}