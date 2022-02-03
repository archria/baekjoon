#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    queue<int> a;
    cin>>n>>k;
    for(int i = 1; i <= n ; i++){
        a.push(i);
    }
    cout<<"<";
    while(!a.empty()){
        int tmp;
        for(int i = 1; i < k ; i++){
            tmp = a.front();
            a.pop();
            a.push(tmp);
        }
        cout<<a.front();
        a.pop();
        if(!a.empty())
        cout<<", ";
    }
    cout<<">";

}