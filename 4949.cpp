#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    while(true){
        string temp;
        stack<char> mystack;
        getline(cin,temp);
        if(temp[0] == '.' && temp.length() == 1) break;
        bool isFalse = false;
        for(int i = 0; i < temp.length() ; i++){
            if(temp[i] == '(' || temp[i] == '['){
                mystack.push(temp[i]);
            }
            else if(temp[i] == ')'){
                if(mystack.size() > 0 && mystack.top() == '(')
                    mystack.pop();
                else{
                    isFalse = true;
                    break;
                }
            }
            else if(temp[i] == ']'){
                if(mystack.size() > 0 && mystack.top() == '[')
                    mystack.pop();
                else{
                    isFalse = true;
                    break;
                }
            }
        }
        if(isFalse == true){
            cout<<"no\n";
        }
        else if(mystack.empty()){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}