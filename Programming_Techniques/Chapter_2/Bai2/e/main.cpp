#include<iostream>

using namespace std;
int main()
{
  long temp, n;
  int S = 0;
  do
  {
    cout<<"\nNhap vao so lon hon 0: ";
    cin>>n;
    if(n <= 0)
    {
      cout<<"\n So nay phai lon hon 0, vui long nhap lai!";
    }
  }while(n <= 0);

  temp = n;
  while(temp != 0)
  {
    if(temp % 2 != 0){
      S = S + temp % 10;
    }
    temp = temp / 10;
  }
  cout<<"\nTong cac so le cua "<<n<<" là: "<< S<<endl;
  return 0;
}
