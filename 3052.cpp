#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int a[10] = {0};
    for(int i = 0; i < 10; i++){
        cin>>a[i];
    }
    int b[42] = {0};
    for( int i = 0; i < 10; i++){
        int k = a[i] % 42;
        b[k] ++;
    }
    int cnt = 0;
    for(int i = 0; i < 42; i++){
        if(b[i] != 0)
            cnt++;
    }
    cout<<cnt;
    return 0;
}