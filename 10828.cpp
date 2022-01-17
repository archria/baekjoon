#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int a;
    stack<int> myStack;
    cin>>a;
    for(int i = 0; i < a; i++){
        string temp;
        cin>>temp;
        if(temp == "push"){
            int b;
            cin>>b;
            myStack.push(b);
        }
        else if(temp == "top"){
            cout<<myStack.top()<<"\n";
        }
        else if(temp == "size"){
            cout<<myStack.size()<<"\n";
        }
        else if(temp == "empty"){
            cout<<myStack.empty()<<"\n";
        }
        else if(temp == "pop"){
            if(myStack.empty() == true){
                cout<<"-1\n";
            }
            else{
                cout<<myStack.top()<<"\n";
                myStack.pop();
            }
        }
    }

    return 0;
}