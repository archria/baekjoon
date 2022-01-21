#include <iostream>
#include <stack>

using namespace std;

int main(){
    int k;
    cin>>k;
    stack<int> mystack;
    for(int i = 0; i < k ; i++){
        int a;
        cin>>a;
        if(a == 0){
            mystack.pop();
        }
        else{
            mystack.push(a);
        }
    }
    int ans = 0;

    int sz = mystack.size();
    for(int i = 0; i < sz ; i++){
        ans += mystack.top();

        mystack.pop();
    }
    cout<<ans;
    
    return 0;
}