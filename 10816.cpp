#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int nums[500000];
int n,m;

int lowerBound(int target){
    int first = 0,mid, last = n-1;
    
    while(true){
        mid = (first+last)/2;
        if(first > last){
            if(nums[first] == target) 
                return first;
            else
                return -1;
        }
        if(nums[mid] >= target) 
            last = mid - 1;
        else
            first = mid + 1;

    }
    
}
int upperBound(int target){
    int first = 0, mid, last = n-1;
    while(true){
        mid = (first+last) / 2;
        if(first > last){
            if(nums[last] == target)
                return last;
            else
                return -1;
        }
        if(nums[mid] <= target)
            first = mid + 1;
        else
            last = mid - 1;
        
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    cin>>m;
    vector<int> howmany(m);
    for(int i = 0; i < m ; i++){
        cin>>howmany[i];
    }
    sort(nums, nums+n);
    for(int i = 0; i < m ; i++){
        if(upperBound(howmany[i]) == -1)
            cout<<"0 ";
        else
            cout<<upperBound(howmany[i]) - lowerBound(howmany[i]) + 1<<" ";
    }

}