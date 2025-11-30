#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int gcb(int a, int b){
    if(b == 0) return a;
    return gcb(b, a % b);
}
int num(vector<int> &arrayA, vector<int> &arrayB){
    // a의 최대공약수가 b를 나눌 수 없을 때 수 return
    // b를 나눌수 있으면 0 return
    int a = arrayA[0];
    for(int i=1;i<arrayA.size();i++){
        a=gcb(a, arrayA[i]);
        if(a==1) return 0; // a의 공약수 x
    }
    if(a!=1){
        // b를 나눌 수 없는지 
        for(int i=0;i<arrayB.size();i++){
            if(arrayB[i]%a==0) {
                return 0;
            }
        }
        return a;
    }
    return 0;

}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int a = num(arrayA, arrayB);
    int b = num(arrayB, arrayA);
    return max(a, b);
}