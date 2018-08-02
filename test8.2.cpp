#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
    int scale=100/5/4;
    int t=105/(7*scale);
    if(t*7*scale<t){
        t++;
    }
    cout<<t<<endl;
    system("pause");
    return 0;
}