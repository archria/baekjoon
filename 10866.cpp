#include <deque>
#include <iostream>
#include <string>

#define endl "\n";
using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int> dq;
    for(int i = 0; i < n ; i++){
        string tmp;
        cin>>tmp;
        if(tmp == "push_front"){
            int a;
            cin>>a;
            dq.push_front(a);
        }
        else if(tmp == "push_back"){
            int a;
            cin>>a;
            dq.push_back(a);
        }
        else if(tmp == "pop_front"){
            if(dq.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<dq.front()<<endl;
                dq.pop_front();
            }
        }
        else if(tmp == "pop_back"){
            if(dq.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<dq.back()<<endl;
                dq.pop_back();
            }
        }
        else if(tmp == "size"){
            cout<<dq.size()<<endl;
        }
        else if(tmp == "empty"){
            cout<<dq.empty()<<endl;
        }
        else if(tmp == "front"){
            if(dq.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<dq.front()<<endl;
            }
        }
        else if(tmp == "back"){
            if(dq.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<dq.back()<<endl;
            }
        }


    }

    return 0;
}