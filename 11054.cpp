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
        //ans = max(ans,_LIS_Array[k]);
    }
    

    // 여기까지의 ans 는 오름차순 가장 큰 수열을 구하는 방법.
    // 역으로 가장 작게 만들 수 있는걸 뒤에서부터 구해서
    // 이 두 경우를 합했을때 가장 긴 길이를 구해야된다.
    for(int k = N-1; k >= 0 ; k--){
        _rev_LIS_Array[k] = 1;
        for(int i = N-1 ; i > k ; i--){
            if(nums[k] > nums[i]){
                _rev_LIS_Array[k] = max(_rev_LIS_Array[k], _rev_LIS_Array[i]+1);
            }
        }
        
    }
    ans = 0;
    for(int i = 0; i < N ; i++){
        if(ans < _rev_LIS_Array[i] + _LIS_Array[i]){
            ans = _rev_LIS_Array[i] + _LIS_Array[i];
        }
    }
    cout<<ans-1;
    // ans -1을 출력하는 이유는 예시 수열에서 12345를 찾고 521을찾기 때문에 5가 중복이다. 그러므로 5를 하나 빼 줘야 한다
    //처음 생각한 방법
    // 오름차순 하나, 내림차순 하나 구해서 단순히 합하고 -1 하려고 했는데
    // 예시로 주어진 수열에서조차 성립하지 않는 모습을 볼 수 있었다.

    return 0;
}