#include <iostream>
#include <queue>

using namespace std;

queue<int> tmp;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        string a;
        cin>>a;
        if(a == "push"){
            int b;
            cin>>b;
            tmp.push(b);
        }
        else if(a == "pop"){
            if(tmp.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<tmp.front()<<"\n";
                tmp.pop();
            }
        }
        else if(a == "size"){
            cout<<tmp.size()<<"\n";
        }
        else if(a == "empty"){
            cout<<tmp.empty()<<"\n";
        }
        else if(a == "front"){
            if(tmp.empty()){
                cout<<"-1\n";
            }
            else
                cout<<tmp.front()<<"\n";
        }
        else if(a== "back"){
            if(tmp.empty()){
                cout<<"-1\n";
            }
            else
                cout<<tmp.back()<<"\n";
        }
    }

    return 0;
}