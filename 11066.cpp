#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        int a;
        cin>>a;
        priority_queue<int, vector<int>, greater<int>> pq;
        int tmp,ans=0;
        for(int j = 0; j < a ; j++){
            cin>>tmp;
            pq.push(tmp);
        }
        while(pq.size() > 1){
            
            int one, two;
            one = pq.top();
            pq.pop();
            two = pq.top();
            pq.pop();
            pq.push(one+two);
            ans += (one+two);
        }
        cout<<ans<<"\n";
    }
    

    return 0;
}