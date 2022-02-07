#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> times(n);
    for(int i = 0; i < n ; i++){
        cin>>times[i].second>>times[i].first; // 종료시간 sort
    }
    sort(times.begin(),times.end());
    int curr = times[0].first;
    int ans = 1;
    for(int i = 1; i < n ; i++){
        if(curr <= times[i].second){
            ans += 1;
            curr = times[i].first;
        }
    }
    cout<<ans;
            

    return 0;
}