#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    cin>>n;
    queue<int> tmp;
    for(int i = 1 ; i <= n ; i++){
        tmp.push(i);
    }
    while(tmp.size() != 1){
        tmp.pop();
        tmp.push(tmp.front());
        tmp.pop();
    }
    cout<<tmp.front();


    return 0;
}