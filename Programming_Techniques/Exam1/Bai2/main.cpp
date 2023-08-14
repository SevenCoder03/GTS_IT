#include <iostream>
#include <math.h>
using namespace std;

void allocation_Arr(int *&a, int n)
{
    a = new int[n];
}

void evict_Arr(int *a)
{
    delete []a;
}

void input_Arr(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu a["<<i<<"]: ";
        cin >> *(a+i);
    }
}

void output_Arr(int *a, int n)
{
    cout << "\nMang vua nhap vao: ";
    for(int i = 0; i < n; i++)
    {
        cout << *(a+i) << " ";
    }
    cout<<endl;
}

void min_Positive_EvenNumber(int *a, int n)
{
    int Min;
    bool Flag = false;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0 && a[i] >= 0)
        {
            Min = a[i];
            Flag = true;
            break;
        }
    }
    if(Flag == false)
    {
        cout << "Mang khong co phan tu chan duong !!!" << endl;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] % 2 == 0 && a[i] >= 0 && a[i] < Min)
            {
                Min = a[i];
            }
        }
        cout << "So chan duong nho nhat la: " << Min << endl;
    }
}

bool check_SquareNumber(int x)
{
    int sqr = sqrt(x);
    if(sqr*sqr == x)
        return true;
    return false;
}

void sort_SquareNumber(int *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        if(check_SquareNumber(*(a+i)) == true)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(*(a+i) < *(a+j) && check_SquareNumber(*(a+j)) == true)
                {
                    swap(*(a+i), *(a+j));
                }
            }
        }
    }
    cout << "Mang sau khi sap xep: ";
    output_Arr(a, n);
}

int main()
{
    int *a = nullptr;
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    allocation_Arr(a, n);
    input_Arr(a, n);
    output_Arr(a, n);
    min_Positive_EvenNumber(a, n);
    sort_SquareNumber(a, n);
    evict_Arr(a);
    return 0;
}
