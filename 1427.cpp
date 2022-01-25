#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool desc(int a, int b){
    if(a > b) return true;
    return false;
}

int main(){
    string temp;
    cin>>temp;
    vector<int> nums;
    for(int i = 0; i < temp.length() ; i++){
        nums.push_back( temp[i] - 48 );
    }
    sort(nums.begin(),nums.end(),desc);
    for(int i = 0; i < nums.size() ; i++){
        cout<<nums[i];
    }
    return 0;
}