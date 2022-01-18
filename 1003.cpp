#include <iostream>

using namespace std;

int zero = 0;
int one = 0;

#define MAX 41


int main(){
    int t;
    cin>>t;
    int zero[41];
    int one[41];
    
    zero[0] = 1;
    one[1] = 1;
    for(int k = 0; k < t ; k++){
        int a;
        cin>>a;
        for (int i = 0; i < 41; i++){
            one[i] = 0;
            zero[i] = 0;
        }
        zero[0] = 1;
        one[1] = 1;
        for (int i = 2; i <= a; i++){
            zero[i] = zero[i - 1] + zero[i - 2];
            one[i] = one[i - 1] + one[i - 2];
        }
        cout<<zero[a]<<" "<<one[a]<<"\n";
    }
    

    return 0;
}