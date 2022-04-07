#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string ans;
    stack<int> primary;
    stack<int> secondary;
    for(int i = n; i > 0 ; i--){
        secondary.push(i);
    }
    bool flag = false;
    for(int i = 0; i < n ; i++){
        int a;
        cin>>a;
        if(primary.empty()){
            primary.push(secondary.top());
            secondary.pop();
            ans += '+';
        }
        if(primary.top() > a){
            cout<<"NO";
            flag = true;
            break;
        }
        else if(primary.top() == a){
            primary.pop();
            ans += '-';
        }
        else{
            while(primary.top() != a){
                primary.push(secondary.top());
                ans += '+';
                secondary.pop();
                if(primary.top() == a){
                    primary.pop();
                    ans += '-';
                    break;
                }
            }        
        }

    }
    if(!flag){
        for(int i = 0; i < ans.length() ; i++){
            cout<<ans[i]<<"\n";
        }
    }

    return 0;
}