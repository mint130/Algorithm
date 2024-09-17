#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int N;
int arr[100002];
long res=9876543210;
int ans[2];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);

    int l, r;
    l=0;
    r=N-1;
    int sum=0;
    
    while(l<r){
        sum=arr[l]+arr[r];
        if(abs(sum)<res){
            res=abs(sum);
            ans[0]=arr[l];
            ans[1]=arr[r];
        }
        if(sum<0){
            l++;
        }
        else {
            r--;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
}