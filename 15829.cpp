#include <iostream>
#include <math.h>
using namespace std;

int mypow(int i, int r){
    int temp = 1;
    for(int a = 1; a <= i ; a++){
        temp *= r;
        temp %= 1234567891;
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    string temp;
    cin>>temp;
    long long ans = 0;
    for(int i = 0; i < n ; i++){
        int pownum = 1;
        for(int j = 1; j <= i ; j++){
            pownum *= 31;
            if(pownum > 1234567891){
                pownum %= 1234567891;
            }
        }
        ans = ans + (temp[i]-'a'+1)*pownum;
        if(ans > 1234567891)
            ans %= 1234567891;
    }
    cout<<ans;

    return 0;
}