#include <iostream>
#include <algorithm>
using namespace std;

int mindiff,sum,mleft,mright,first,last;
int fluid[100000];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>fluid[i];
    }
    sort(fluid,fluid+n);
    mindiff = fluid[0] + fluid[n-1];
    first = 0; last = n-1;
    mleft = 0; mright = n-1;
    while(true){
        sum = fluid[first] + fluid[last];
        if(abs(mindiff) > abs(sum)){
            mindiff = sum;
            mleft = first;
            mright = last;
        }
        if(first == last - 1){
            break;
        }
        if(sum < 0){
            first++;
        }
        else if(sum > 0){
            last--;
        }
        else if(sum == 0){
            break;
        }
    }
    cout<<fluid[mleft]<<" "<<fluid[mright]<<endl;
    

    return 0;
}