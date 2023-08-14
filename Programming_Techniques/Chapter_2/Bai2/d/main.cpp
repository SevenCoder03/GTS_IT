#include <iostream>
using namespace std;

int main(){
    int n,r,s=0,tmp;

    cout << "Enter a number: ";
    cin >> n;

    for(tmp=n;n!=0;n=n/10){
         r=n%10;
         s=s*10+r;
    }
    if(tmp==s)
         cout << tmp << " la so doi xung";
    else
         cout << tmp << " khong la so doi xung";
    cout<<endl;
    return 0;
}
