#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,ans=0;
    cin>>n>>m;
    vector<string> cont;
    vector<string> anscont;
    for(int i = 0; i < n+m; i++){
        string temp;
        cin>>temp;
        cont.push_back(temp);
    }
    sort(cont.begin(), cont.end());
    for(int i = 0; i < n+m ; i++){
        if(cont[i] == cont[i+1]){
            ans += 1;
            anscont.push_back(cont[i]);
            i+=1;
        }
    }
    cout<<ans<<"\n";
    for(int i = 0; i < anscont.size() ; i++){
        cout<<anscont[i]<<"\n";
    }
    return 0;
}