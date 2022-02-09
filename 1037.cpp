#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int yakNum;
    cin>>yakNum;
    vector<int> yaks(yakNum);
    for(int i = 0; i < yakNum ; i++){
        cin>>yaks[i];
    }
    sort(yaks.begin() , yaks.end());
    if(yakNum %2 == 1){
        cout<<yaks[ yakNum/2] * yaks[yakNum/2];
    }
    else{
        cout<<yaks[0] * yaks[yakNum-1];
    }

    return 0;
}