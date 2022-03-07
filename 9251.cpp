#include <iostream>
#include <string>

using namespace std;
int lcs[1001][1001] = {0,};

int main(){
    string temp1, temp2;
    cin>>temp1>>temp2;
    int n = temp1.length();
    for(int i = 0; i < temp1.length(); i++){
        for(int j = 0 ; j < temp2.length() ; j++){
            if(temp1[i] == temp2[j]){
                lcs[i+1][j+1] = lcs[i][j] + 1;
            }
            else{
                lcs[i+1][j+1] = max(lcs[i][j+1],lcs[i+1][j]);
            }
        }
    }
    cout<<lcs[temp1.length()][temp2.length()];

    return 0;
}