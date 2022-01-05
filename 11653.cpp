#include <iostream>

using namespace std;

int soinsu(int n){
    for(int i = 2; i <= n/2 ; i++){
        if(n%i == 0){
            cout<<i<<endl;
            return n/i;
        }
    }
    return n;
}

int main(){
    int n;
    cin>>n;
    if(n == 1)
        return 0;
    while(true){
        int tmp = soinsu(n);
        if(tmp == n){
            cout<<n;
            break;
        }
        else{
            n = tmp;
        }
        
    }
    
    return 0;
}