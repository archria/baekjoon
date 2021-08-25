#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> t;
    t.push(1);
    t.push(3);
    t.push(2);

    while(t.empty() == false){
        cout<<t.front()<<endl;
        t.pop();
    }
}