#include <iostream>
#include <string>

using namespace std;

int main(){
    string temp;
    while(true){
        cin>>temp;
        if(temp == "0") break;
        bool flag = false;
        for(int i = 0; i < temp.length()/2 ; i++){
            if(temp[i] != temp[temp.length() -1 - i]){
                flag = true;
                break;
            }
        }
        if(flag == true){
            cout<<"no\n";
        }
        else{
            cout<<"yes\n";
        }

    }

    return 0;
}