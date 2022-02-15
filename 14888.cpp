#include <iostream>
#include <vector>
using namespace std;

int min = 1000000000, max = -10000000000;
vector<int> ops(4);
int n;
void backtrack(int cnt){
    

    if(cnt == n-1){

    }    
}

int main(){



    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    for(int i = 0; i < 4 ; i++){
        cin>>ops[i];
    }
    //backtrack(0);    
    cout<<max<<"\n"<<min;

    return 0;
}