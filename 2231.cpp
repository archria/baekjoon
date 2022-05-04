#include <iostream>
#include <string>

using namespace std;

int boonhaehap(int num){
    int ans = 0;
    ans += num;
    string snum = to_string(num);
    for(int i = 0 ; i < snum.length() ; i++){
        ans += snum[i] - '0';
    }
    return ans;
}

int main(){
    int a;
    cin>>a;
    bool isPossible = false;
    for(int i = 1; i < 1000001; i++){
        if(boonhaehap(i) == a){
            isPossible = true;
            cout<<i;
            break;
        }
    }
    if(isPossible == false){
        cout<<"0";
    }

    return 0;
}