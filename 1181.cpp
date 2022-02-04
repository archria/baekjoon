#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool sorting(string left, string right){
    if(left.length() < right.length()){
        return true;
    }
    else if(left.length() > right.length()){
        return false;
    }
    else if(left.length() == right.length()){
        for(int i = 0; i < left.length() ; i++){
            if(left[i] < right[i])
                return true;
            else if(left[i] > right[i])
                return false;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<string> words;
    for(int i = 0; i < n ; i++){
        string temp;
        cin>>temp;
        words.push_back(temp);
    }
    sort(words.begin(),words.end());
    words.erase(unique(words.begin(),words.end()),words.end());
    sort(words.begin(), words.end(), sorting);
    for(int i = 0; i < words.size() ; i++){
        cout<<words[i]<<"\n";
    }

    return 0;
}