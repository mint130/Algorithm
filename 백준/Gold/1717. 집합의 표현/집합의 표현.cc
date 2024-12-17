#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int p[1000002]; //부모 인덱스 저장 
int find_set(int a){
    if(a==p[a]) return a; 
    else return p[a]=find_set(p[a]);
}
void union_set(int a, int b){
    if(find_set(b)==find_set(a)) return; 
    p[find_set(b)]=find_set(a);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=0;i<m;i++){
        int a, b, input;
        cin>>input>>a>>b;
        if(input==0){
            //a와 b의 집합 합침 
            union_set(a,b);
        }
        else {
            //a와 b가 같은 집합에 포함되어 있는지 
            if(find_set(a)==find_set(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }

    }

}