#include <iostream>
#include <math.h>
using namespace std;

int main(){
    bool isTimeNumber[246913] = {false};
    for(int i = 2 ; i <= sqrt(246913) ; i++){
        if(isTimeNumber[i] == false){
            for(int j = 2 ; j < 246913 ; j++){
                if(i*j > 246912) break;
                isTimeNumber[i*j] = true;
            }
        }
    }
    while(true){
        int n;
        cin>>n;
        if(n == 0 ) break;
        int ans = 0;
        for(int i = n+1 ; i <= 2*n ; i++){
            if(isTimeNumber[i] == false)
                ans++;
        }
        cout<<ans<<"\n";

        
    }

    return 0;
}