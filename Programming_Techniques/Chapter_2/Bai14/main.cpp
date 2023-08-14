#include <iostream>
using namespace std;

int main(){
    int n, Count=0, Sum=0, SumChan=0;
    cout << "\nNhap n = ";
    do{
        cin >> n;
        if(n <= 0){
            cout << "\nNhap lai n = ";
        }
    }while(n <= 0);

    cout<<"Cac uoc cua n la: ";
    for(int i = 1;i <= n;i++)
    {
        if(n % i == 0){
            cout << i << " ";
            if(i%2 == 0)
            {
                SumChan+=i;
            }
            Sum+=i;
            Count++;
        }
    }
    cout<<endl;
    cout<<"So uoc la: "<<Count<<endl;
    cout<<"Tong cac uoc la: "<<Sum<<endl;
    cout<<"Tong cac uoc chan la: "<<SumChan<<endl;
    return 0;
}
