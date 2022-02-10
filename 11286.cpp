#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> plus;
    priority_queue<int> minus;
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        int a;
        cin>>a;
        if(a > 0){
            plus.push(a * (-1));
        }
        else if(a < 0){
            minus.push(a);
        }
        else{
            if(plus.empty() && minus.empty()){
                cout<<"0\n";
            }
            else if(plus.empty()){
                cout<<minus.top()<<"\n";
                minus.pop();
            }
            else if(minus.empty()){
                cout<<plus.top() * (-1)<<"\n";
                plus.pop();
            }
            else {
                int ptop, mtop;
                ptop = plus.top();
                mtop = minus.top();
                if (ptop > mtop) {
                    cout << ptop * (-1) << "\n";
                    plus.pop();
                }
                else {
                    cout << mtop << "\n";
                    minus.pop();
                }
            }
        }
        
    }

    return 0;
}