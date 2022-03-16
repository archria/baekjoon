#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int ans[10000];

int GCD(int a, int b){
    if(a % b == 0){
        return b;
    }
    return GCD(b, a%b);
}

int main(){
    int N;
    cin>>N;
    vector<int> nums(N);
    for(int i = 0; i < N ; i++){
        cin>>nums[i];
    }
    sort(nums.begin() , nums.end());

    int myGCD = nums[1] - nums[0];
    for(int i = 2; i < N ; i++){
        myGCD = GCD(myGCD, nums[i] - nums[i-1]);
    }
    int cnt = 0;
    
    for(int i = 1; i*i <= myGCD ; i++){
        if(myGCD%i == 0){
            ans[cnt++] = i;
            //cout<<"i : "<<i;
            if(i != myGCD / i) ans[cnt++] = myGCD/i;
        }
    }
    sort(ans, ans+cnt);
    //cout<<"cnt : "<<cnt<<endl;
    for(int i = 0; i < cnt ; i++){
        if(ans[i] != 1)
            cout<<ans[i]<<" ";
    }

    return 0;
}