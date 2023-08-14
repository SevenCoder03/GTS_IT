#include <iostream>
using namespace std;

void input_Arr(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>*(a+i);
    }
}
void Max_Arr(int *a, int n, int &Max, int &index)
{
    for(int i=1; i<n; i++)
    {
        if(*(a+i) > Max)
        {
            Max = *(a+i);
            index = i;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    input_Arr(a, n);
    int Max = *a, index = 0;
    Max_Arr(a, n, Max, index);
    cout<<"Gia tri lon nhat mang la: "<<Max<<" vi tri la: "<<index;
    delete []a;
    return 0;
}
