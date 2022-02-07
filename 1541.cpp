#include <iostream>
#include <string>

using namespace std;

bool minusState = false;

int main(){
    string temp;
    cin>>temp;
    string num;
    int ans;
    for(int i = 0; i < temp.length() ; i++){
        if(temp[i] >= '0' && temp[i] <= '9'){
            num += temp[i];
        }
        else if(temp[i] == '-'){
            int a = stoi(num);
            num = "";
            if(minusState == true){
                ans -= a;
            }
            else{
                ans += a;
            }
            minusState = true;
            
        }
        else if(temp[i] == '+'){
            int a = stoi(num);
            num = "";
            if(minusState == true){
                ans -= a;
            }
            else{
                ans += a;
            }
        }
        if(i == temp.length() - 1){
            int a = stoi(num);
            if(minusState == true){
                ans -= a;
            }
            else{
                ans += a;
            }

        }

    }
    cout<<ans;
    
    return 0;
}
