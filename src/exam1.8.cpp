#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout<<"9/8="<<9/8<<" 9.0/8="<<9.0/8<<" 9/8.0="<<9/8.0<<" 9.0/8.0="<<9.0/8.0<<endl;
    cout<<"100.0/6.0="<<100.0/6.0<<endl;
    cout<<"100.0/6.0="<<fixed<<setprecision(8)<<100.0/6.0<<endl;
    system("pause");
    return 0;
}