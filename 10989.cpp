#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    int nums[10001] = {0};
    int temp = 0;
    for(int i = 0; i < n ; i++){
        cin>>temp;
        nums[temp] += 1;
    }
    for(int i = 1; i < 10001 ; i++){
        for(int j = 0; j < nums[i] ; j++){
            cout<<i<<"\n";
        }
    }

    return 0;
}


//메모리 초과뜨는 방법
/*int main(){
    int n;
    cin>>n;
    int *nums = new int[n];
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    for(int i = 0; i < n ; i++){
        cout<<nums[i]<<"\n";
    }


    return 0;
}*/