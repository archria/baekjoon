#include <iostream>

using namespace std;

bool sosu[10001];

int main(){
    for(int i = 2; i < 10001; i++){
        sosu[i] = true;
    }
    sosu[1] = false;
    for(int i = 2 ; i <= 101 ; i++){
        if(sosu[i] == true){
            for (int j = 2; j < 10001 / i; j++) {
                sosu[i*j] = false;
            }
        }
    }
    int T;
    cin>>T;
    for(int i = 0; i < T ; i++){
        int n;
        cin>>n;
        int p1, p2;
        p1 = p2 = n/2;
        while(true){
            if (sosu[p1] == true && sosu[p2] == true) {
                cout << p1 << " " << p2 << "\n";
                break;
            }
            else {
                p1--;
                p2++;
            }
        }
    }

    return 0;
}