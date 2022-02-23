#include <iostream>

using namespace std;

int main(){
    long long padovan[101] = {0,};
    padovan[1] = padovan[2] = padovan[3] = 1;
    for(int i = 4; i < 101 ; i++){
        padovan[i] = padovan[i-3] + padovan[i-2];
    }
    int T;
    cin>>T;
    int temp;
    for(int i = 0; i < T; i++){
        cin>>temp;
        cout<<padovan[temp]<<"\n";
    }
    return 0;
}