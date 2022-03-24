#include <iostream>
#include <vector>
using namespace std;

bool notsosu[4000001] = {false,};

int main(){
    notsosu[0] = true;
    notsosu[1] = true;
    for(int i = 2; i <=2000; i++){
        if(notsosu[i] == false){
            for(int j = 2; j < 4000000/i ; j++){
                notsosu[i*j] = true;
            }
        }
    }
    vector<int> sosu;
    for(int i = 2; i < 4000000; i++){
        if(notsosu[i] == false){
            sosu.push_back(i);
        }
    }
    int n;
    cin>>n;
    int first = 0, last = 0,ans = 0;
    int sum = sosu[0];
    bool hit = false;
    while(first < last){
        if(n == sum){
            ans += 1;
            sum -= sosu[first];
            first += 1;
        }
        else if(sum < n){
            last += 1;
            if(last == sosu.size()) break;
            sum += sosu[last];
        }
        else if(sum > n){
            sum -= sosu[first];
            first += 1;
        }
    }
    cout<<ans;


    return 0;
}