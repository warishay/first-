#include <iostream>
using namespace std;
int main() {
    const double pi=3.1415;
    double radius;
    double area;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;
    area=pi*radius*radius;
    cout<<"The area of the circle is: "<<area<<endl;
    return 0;
}
