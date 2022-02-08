#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> city(n-1);
    vector<long long> oil(n); 
    for(int i = 0; i < n-1 ; i++){
        cin>>city[i];
    }
    for(int i = 0; i < n ; i++){
        cin>>oil[i];
    }
    long long currentOil = oil[0]; // 첫 지점에서는 무조건 기름을 사야함.
    long long totalOil = city[0] * oil[0];
    for(int i = 1; i < n-1 ; i++){
        if( oil[i] < currentOil ){
            currentOil = oil[i];
        }
        totalOil += currentOil * city[i];
    }
    cout<<totalOil;       
    


    return 0;
}