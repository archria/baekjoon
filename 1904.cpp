#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long ans;
    vector<long long> tmp(n);
    tmp[0] = 1;
    if(n > 1) tmp[1] = 2;
    for(int i = 2; i < n ; i++){
        tmp[i] = (tmp[i-1] + tmp[i-2])%15746;
    }
    cout<<tmp[n-1];

    return 0;
}