#include <iostream>

using namespace std;

int main(){
    
    int num;
    int ans = 0;
    string input;
    cin>>num;
    for(int i = 0; i < num ; i++){
        bool alphabet[26] = {false};
        cin>>input;
        int k = -1;
        for(int j = 0; j < input.length(); j++){
            // 방문한 적 없고, 새로 나타난 알파벳이라면?
            if(input[j] - 'a' != k && alphabet[ input[j] - 'a' ] == false){
                k = input[j] - 'a';
                alphabet[ input[j] - 'a'] = true;
            }
            // 방문한 적 있고, 또 나타난 알파벳이라면?
            else if(input[j] - 'a' != k && alphabet [input[j] - 'a'] == true){
                break;
            }
            if (j == input.length() - 1){
                ans++;
            }
        }
    }
    cout<<ans;
}



