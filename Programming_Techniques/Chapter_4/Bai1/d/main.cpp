#include <iostream>
using namespace std;

void input_Arr(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>*(a+i);
    }
}
void sort_Arr(int *a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(*(a+i) > *(a+j))
            {
                swap(*(a+i), *(a+j));
            }
        }
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(*(a+j) < 0)
            {
                swap(*(a+i), *(a+j));
            }
            else
            {
                break;
            }
        }
    }
}
void output_Arr(int *a, int n)
{
    for(int i=0; i<n; i++)
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
    sort_Arr(a, n);
    cout<<"Mang sau khi sap xep: "<<endl;
    output_Arr(a, n);
    delete []a;
    return 0;
}
