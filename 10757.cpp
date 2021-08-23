#include <iostream>
#include <string>
#include <stack>


using namespace std;
int main(){
    string temp1;
    string temp2;
    cin>>temp1;
    cin>>temp2;
    int lendiff = 0;
    int up = 0; // 반올림
    int biggerLength = 0;
    stack<int> tmp1;
    stack<int> tmp2;
    stack<int> tmp3;
    for(int i = 0; i < temp1.length(); i++){
        tmp1.push(int(temp1[i]-48));
    }
    for(int i = 0; i < temp2.length(); i++){
        tmp2.push(int(temp2[i]-48));
    }
    while(tmp1.size() != 0 && tmp2.size() != 0){
        int sum = tmp1.top() + tmp2.top() + up;
        if(sum >= 10){
            sum -=10;
            up = 1;
        }
        else
            up = 0;
        tmp1.pop(); tmp2.pop();
        tmp3.push(sum);
        
    }
    if (tmp1.size() != 0)
    {
        
        while (tmp1.size() != 0)
        {
            int sum = tmp1.top() + up;
            if(sum >= 10){
                sum -= 10;
                up = 1;
            }
            else
                up = 0;
            tmp3.push(sum);
            tmp1.pop();
        }
    }
    else if (tmp2.size() != 0)
    {
        while (tmp2.size() != 0)
        {
            int sum = tmp2.top() + up;
            if(sum >= 10){
                sum -=10;
                up = 1;
            }
            else
                up = 0;
            tmp3.push(sum);
            tmp2.pop();
        }
    }
    else
    {
        if (up == 1)
            tmp3.push(1);
    }
    if(temp1.length() != temp2.length() && up == 1)
        cout<<'1';
    while(tmp3.size() != 0){
        cout<<tmp3.top();
        tmp3.pop();
    }
    return 0;
}