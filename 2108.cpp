#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double n;
    cin>>n;
    double sum = 0;
    int nums[8001] = {0};
    for(int i = 0; i < n ; i++){
        int a;
        cin>>a;
        sum += a;
        a += 4000;
        nums[a] += 1;
    }

    int mid = n/2;
    int tmp = 0;

    double mean = sum / n;
    mean = round(mean);
    if(mean == -0) mean = 0;
    cout<<round(mean)<<"\n";

    for(int i = 0; i < 8001; i++){
        tmp += nums[i];
        if(tmp >= mid+1){
            cout<<i-4000<<"\n";
            break;
        }
    }

    int maxNum = 0;
    int maxNumCount = 0;
    bool isMany = false;
    for(int i = 0; i < 8001; i++){
        if(maxNumCount < nums[i]){
            maxNumCount = nums[i];
            maxNum = i;
            isMany = false;
        }
        else if(maxNumCount == nums[i]){
            isMany = true;
        }
    }
    if(isMany == false){
        cout<<maxNum-4000<<"\n";
    }
    else if(isMany == true){
        bool isFirst = false;
        for(int i = 0; i < 8001; i++){
            if(isFirst == false && nums[i] == maxNumCount){
                isFirst = true;
            }
            else if(isFirst == true && nums[i] == maxNumCount){
                cout<<i-4000<<"\n";
                break;
            }

        }
    }

    
    int min = 0, max = 0;
    for(int i = 0; i < 8001; i++){
        if(nums[i] != 0){
            min = i- 4000;
            break;
        }
    }
    for(int i = 8000; i >= 0 ; i--){
        if(nums[i] != 0){
            max = i-4000;
            break;
        }
    }
    cout<<max-min;
    
    

    return 0;
}