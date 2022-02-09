#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i = 0; i < n ; i++){
        int docNum = 0;
        int interest = 0;
        int ans = 0;
        cin>>docNum>>interest;
        queue<pair<int,int>> docs;
        priority_queue<int> pq;
        for(int j = 0; j < docNum ; j++){
            int importance = 0;
            cin>>importance;   
            docs.push({j,importance});
            pq.push(importance);         
        }
        while(!docs.empty()){
            pair<int,int> docFront;
            int bigImportance;
            docFront = docs.front();
            bigImportance = pq.top();
            docs.pop();
            if(docFront.second == bigImportance){
                pq.pop();
                ans++;
                if(docFront.first == interest){
                    cout<<ans<<"\n";
                    break;
                }
            }
            else{
                docs.push(docFront);
            }
            
        }
    }


    return 0;
}