#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k,n;
int wires[10001];
int ans;

bool isPossible(int len){
    int cuts = 0;
    for(int i = 0; i < k ; i++){
        cuts += wires[i]/len;
    }
    return cuts>=n;
}

int main(){
    cin>>k>>n; // k 는 가진거 n은 필요한거
    for(int i = 0; i < k ; i++){
        cin>>wires[i];
    }
    sort(wires,wires+k);
    int first = 1,mid,last = wires[k-1];
    while(true){
        mid = (first + last)/2;
        if(first > last){
            break;
        }
        if(isPossible(mid)){
            first = mid+1;
        }
        else{
            last = mid - 1;
        }

    }
    cout<<last;

    return 0;
}