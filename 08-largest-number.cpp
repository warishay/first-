#include <iostream>
using namespace std;
int main () {
    int num1;
    int num2;
    cout<<"Enter first number: "<<endl;
    cin>>num1;
    cout<<"Enter secod number: "<<endl;
    cin>>num2;
    if(num1>num2)
    {
        cout<<"The largest number is: "<<num1<<endl;
    }
    else if
    (num2>num1)
    {
        cout<<"The largest number is: "<<num2<<endl;
    }else
    {
        cout<<"Both numbers are equal."<<endl;
    }
    return 0;
}