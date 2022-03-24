#include <iostream>
#include <algorithm>

using namespace std;

int nums[100000];
int n,s,first,last,sum, ans = 100001,myLeft, myRight;

int main(){
    cin>>n>>s;
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    first = 0; last = 0;
    sum = nums[0];
    while(true){
        if(sum < s){
            last++;
            if(last == n) break;
            sum += nums[last];
        }
        else if(sum >= s){
            int length = last - first + 1;
            if(length < ans){
                ans = length;
                //cout<<"ans : "<<ans<<"\n";
            }
            sum -= nums[first];
            first += 1;
        }

    }
    if(ans == 100001){
        cout<<"0";
    }
    else{
        cout<<ans;
    }

    return 0;
}