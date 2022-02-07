#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> times(n);
    for(int i = 0; i < n ; i++){
        cin>>times[i];
    }
    sort(times.begin(),times.end());
    int ans = 0;
    for(int i = 0; i < n ; i++){
        ans += times[i] * (n-i);
    }
    cout<<ans;
    return 0;
}