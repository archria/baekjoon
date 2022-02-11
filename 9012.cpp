#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        string temp;
        cin>>temp;
        stack<char> ps;
        bool no = false;
        for(int j = 0; j < temp.length() ; j++){
            if(temp[j] == '('){
                ps.push('(');
            }
            else{
                if(!ps.empty()){
                    ps.pop();
                }
                else{
                    cout<<"NO\n";
                    no = true;
                    break;
                }
            }
        }
        if(no == true){
            continue;
        }
        if(ps.empty()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}   