#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int *nums = new int[N];
    for(int i = 0; i < N ; i++){
        cin>>nums[i];
    }
    int *_LIS_Array = new int[N];
    int ans = 0;
    for(int k = 0; k < N ; k++){
        _LIS_Array[k] = 1;
        for(int i = 0; i < k ; i++){
            if(nums[k] > nums[i]){
                _LIS_Array[k] = max(_LIS_Array[k], _LIS_Array[i] + 1);
            }
        }
        ans = max(ans,_LIS_Array[k]);
    }
    cout<<ans;
    return 0;
}