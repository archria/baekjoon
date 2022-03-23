#include <iostream>
#include <algorithm>
using namespace std;

long long trees[1000001];
long long target, ans = 0;
long long n,m;


bool myTree(int len){
    long long mine = 0;
    for(int i = 0; i < n ; i++){
        if(trees[i] > len){
            mine += trees[i] - len;
        }
    }    
    return mine >= m;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n ; i++){
        cin>>trees[i];
    }
    sort(trees, trees+n);
    long long first = 1, mid , last = trees[n-1];
    while(true){
        mid = (first + last) / 2;
        if(first > last){
            break;
        }
        if(myTree(mid)){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }
    }
    cout<<last;

    return 0;
}