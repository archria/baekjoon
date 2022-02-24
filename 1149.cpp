#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int rgb[1001][3] = {0,};
    for(int i = 1; i < n+1 ; i++){
        int r,g,b;
        cin>>r>>g>>b;
        rgb[i][0] = r + min(rgb[i-1][1],rgb[i-1][2]);
        rgb[i][1] = g + min(rgb[i-1][0],rgb[i-1][2]);
        rgb[i][2] = b + min(rgb[i-1][0],rgb[i-1][1]);
    }
    cout<<min(rgb[n][0],min(rgb[n][1],rgb[n][2]));

    return 0;
}