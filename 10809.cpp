#include <iostream>

using namespace std;

int main(){
    string S;
    cin>>S;
    int where[26];
    for(int i = 0; i < 26; i++){
        where[i] = -1;
    }
    for(int i = 0; i < S.length(); i++){
        if(where[S[i]-'a'] == -1 ) 
            where[S[i]-'a'] = i;
    }
    for(int i = 0; i < 26; i++){
        cout<<where[i]<<" ";
    }
    return 0;


}