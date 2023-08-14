#include<iostream>
using namespace std;
int main()
{
  int n;
  do
  {
    cout<<"\nNhap vao so nguyen duong n: ";
    cin>>n;
    if (n <= 0)
    {
      cout<<"\n Sai, vui long nhap lai ";
    }
  } while (n <= 0);

  bool Flag = true;
  int tmp = n;
  int m = tmp % 10;
  tmp /= 10;

  while(tmp != 0)
  {
    int l = tmp % 10;
    tmp /= 10;
    if (m > l)
    {
      Flag = false;
      break;
    }
    else
    {
      m = l;
    }
  }
  if(Flag)
    cout<<"\nCac chu so giam dan tu trai sang phai !";
  else
    cout<<"Cac chu so khong giam dan tu trai sang phai !";
  cout<<endl;
  return 0;
}
