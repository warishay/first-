#include <iostream>
using namespace std;
int main() {
    int a;
    int b;
    int temp;
cout<<"Enter first number: "<<endl;
cin>>a;
cout<<"Enter second number: "<<endl;
cin>>b;
cout<<"/n---Before Swapping---/n"<<endl;
cout<<"First number: "<<a<<endl;
cout<<"Second number: "<<b<<endl;
temp=a;
a=b;
b=temp;
cout<<"/n---After Swapping---/n"<<endl;
cout<<"First number: "<<a<<endl;
cout<<"Second number: "<<b<<endl;
    return 0;
}