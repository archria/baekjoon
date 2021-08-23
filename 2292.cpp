#include <iostream>

using namespace std;

int main(){
    int N = 0;
    int sum = 1;
    int ans = 0;
    int i = 1;
    cin>>N;
    if(N == 1)
        ans = 1;
    else {
        while (true) {
            sum += i * 6;
            i++;
            ans = i;
            if (N <= sum)
                break;
        }
    }
    cout<<ans;

}