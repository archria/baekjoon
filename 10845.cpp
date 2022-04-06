#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;\
    queue<int> tmp;
    for(int i = 0; i < n ; i++){
        string temp;
        cin>>temp;
        if(temp == "push"){
            int a;
            cin>>a;
            tmp.push(a);
        }
        else if(temp == "pop"){
            if(!tmp.empty()){
                cout<<tmp.front()<<"\n";
                tmp.pop();
            }
            else{
                cout<<"-1"<<"\n";
            }
        }
        else if(temp == "size"){
            cout<<tmp.size()<<"\n";
        }
        else if(temp == "empty"){
            cout<<tmp.empty()<<"\n";
        }
        else if(temp == "front"){
            if(tmp.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<tmp.front()<<"\n";
            }
        }
        else if(temp == "back"){
            if(tmp.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<tmp.back()<<"\n";
            }
        }
    }
    


    return 0;
}