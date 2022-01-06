#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int m,n;
    cin>>m;
    cin>>n;
    
    bool isPrime[1000001] = {false};
    isPrime[1] = true;
    for(int i = 2; i < sqrt(1000000); i++){
        if(isPrime[i] == false){
            for(int j = i ; j < 1000000; j++){
                if(i*j > 1000000) break;
                isPrime[i*j] = true;
            }
        }
    }
    for(int i = m ; i <= n ; i++){
        if(isPrime[i] == false)
            cout<<i<<"\n";
            // endl은 상당히 느리다 \n을 사용하자
    }

    return 0;
}