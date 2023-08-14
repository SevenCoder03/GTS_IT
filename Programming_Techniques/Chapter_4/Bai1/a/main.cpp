#include <iostream>
using namespace std;

void input_Arr(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>*(a+i);
    }
}
void output_Arr(int *a, int n)
{
    for(int i=n-1; i>=0; i--)
    {
        cout<<*(a+i)<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    input_Arr(a, n);
    output_Arr(a, n);
    delete []a;
    return 0;
}
