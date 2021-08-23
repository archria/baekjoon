#include <iostream>
#include <vector>

long long sum(std::vector<int> &a);

int main(){
    
    return 0;
}


long long sum(std::vector<int> &a){
    int size = a.size();
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += a[i];
    }
    return sum;    
}