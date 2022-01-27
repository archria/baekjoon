#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector<int> a;

bool isThere(int target){
    int start = 0;
    int end = n-1;
    int mid;

    while(end >= start){
        mid = (start+end)/2;
        if(a[mid] == target){
            return true;
        }
        else if(a[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return false;
    
}

int main(){
    cin>>n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < n ; i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin() , a.end());

    cin>>m;
    for(int i = 0; i < m ; i++){
        int b;
        cin>>b;
        cout<<isThere(b)<<"\n";        
    }

    return 0;
}