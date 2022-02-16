#include <iostream>
#include <vector>
using namespace std;

int minans = 1000000000, maxans = -10000000000;
int ops[4];
int nums[11];
int n;

void backtrack(int ans, int cnt){
    

    if(cnt == n){
        if(ans > maxans){
            maxans = ans;
        }
        if(ans < minans){
            minans = ans;
        }
    }
    for(int i = 0; i < 4 ; i++){
        if(ops[i] > 0){
            ops[i] -= 1;
            if(i == 0){
                backtrack(ans + nums[cnt], cnt+1);
            }
            else if(i == 1){
                backtrack(ans - nums[cnt] , cnt+1);
            }
            else if(i == 2){
                backtrack(ans * nums[cnt] , cnt+1);
            }
            else{
                backtrack(ans / nums[cnt] , cnt+1);
            }
            ops[i] += 1;
        }
    }

}

int main(){

    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    for(int i = 0; i < 4 ; i++){
        cin>>ops[i];
    }
    backtrack(nums[0], 1);    
    cout<<maxans<<"\n"<<minans;

    return 0;
}
