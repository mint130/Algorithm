#include <iostream>
using namespace std;


int recursion(int n, int m){
	
   // cout<<n<<endl;
    if(m==1) return n;
    else {
        return n*recursion(n, m-1);
    }

}
int main() {

	for(int i=0;i<10;i++){
    	int tc;
        cin>>tc;
        int n, m;
        cin>>n>>m;
        //n을 m번 거듭제곱
        
        
        
        
        cout<<"#"<<tc<<" "<<recursion(n,m)<<endl;
    
    
    }
}