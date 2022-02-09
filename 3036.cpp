#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int tmp, n;

    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    vector<int> rings(n);
    for(int i = 0; i < n ; i++){
        cin>>rings[i];
    }
    for(int i = 1; i < n ; i++){
        int g = gcd(rings[0],rings[i]);
        cout<< rings[0]/g <<"/"<< rings[i]/g <<"\n";
    }


    return 0;
}