#include <iostream>
#include <string>

using namespace std;

bool minusState = false;

int main(){
    string temp;
    cin>>temp;
    string num = "";
    int ans = 0;
    for(int i = 0; i <= temp.length() ; i++){
        if(temp[i] == '-' || temp[i] == '+' || i == temp.length()){
            if(minusState){
                ans -= stoi(num);
                num = "";
            }
            else{
                ans += stoi(num);
                num = "";
            }
        }
        else{
            num += temp[i];
        }

        if(temp[i] == '-'){
            minusState = true;
        }

    }
    cout<<ans;
    
    return 0;
}
