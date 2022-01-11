#include <iostream>

using namespace std;

int fivonaci(int a, int b, int num,int target){
    if(num == target){
        cout<<b;
        return 0;
    }

    return fivonaci(b,a+b,num+1,target);
}

int main(){
    int target;
    cin>>target;
    if(target == 0){
        cout<<"0";
        return 0;
    }
    else if(target == 1){
        cout<<"1";
        return 0;
    }
    else if(target == 2){
        cout<<"1";
        return 0;
    }
    else 
        fivonaci(0,1,2,target+1);
    

    return 0;
}