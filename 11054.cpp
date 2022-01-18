#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int *nums = new int[N];
    int *revnums = new int[N];
    for(int i = 0; i < N ; i++){
        cin>>nums[i];
        revnums[N-1-i] = nums[i];
    }
    int *_LIS_Array = new int[N];
    int *_rev_LIS_Array = new int[N];
    int ans = 0;
    int revans = 0;
    for(int k = 0; k < N ; k++){
        _LIS_Array[k] = 1;
        for(int i = 0; i < k ; i++){
            if(nums[k] > nums[i]){
                _LIS_Array[k] = max(_LIS_Array[k], _LIS_Array[i] + 1);
            }
        }
        ans = max(ans,_LIS_Array[k]);
    }
    

    // 여기까지의 ans 는 오름차순 가장 큰 수열을 구하는 방법.
    //

    return 0;
}