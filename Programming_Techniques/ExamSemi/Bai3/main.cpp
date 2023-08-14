#include<iostream>
using namespace std;

void Allocation(int *&a, int n)
{
    a = new int [n];
}

void Evict(int *a)
{
    delete []a;
}

void input_Arr(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> *(a + i);
    }
}

void output_Arr(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    cout<<endl;
}

bool check_Prime(int x)
{
    if(x < 2)
        return false;
    for(int i=2; i*i <= x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

int count_Prime(int *a, int n)
{
    int Count = 0;
    for(int i=0; i<n; i++)
    {
        if(check_Prime(*(a+i)) == true)
        {
            Count++;
        }
    }
    return Count;
}

void sort_Prime(int *a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(check_Prime(*(a+i)) == true)
        {
            for(int j=i+1; j<n; j++)
            {
                if(check_Prime(*(a+j)) == true && *(a+i) > *(a+j))
                {
                    swap(*(a+i), *(a+j));
                }
            }
        }
    }
}

void resize_Arr(int *&a, int oldsize, int newsize)
{
      int *b = new int[oldsize];
      for (int i = 0; i < oldsize; ++i)
      {
            b[i] = a[i];
      }
      delete[] a;
      a = new int[newsize];
      int Min = oldsize < newsize ? oldsize : newsize;
      for (int i = 0; i < Min; ++i)
      {
            a[i] = b[i];
      }
      delete[] b;
}

void delete_Arr(int *&a, int &n, int pos)
{
    for(int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    resize_Arr(a, n, n--);
}

void delete_Prime(int *&a, int &n)
{
    for(int i=0; i<n; i++)
    {
        if(check_Prime(*(a+i)) == true)
        {
            delete_Arr(a, n, i);
            i--;
        }
    }
}

int main()
{
    int *a = nullptr;
    int n;
    int select;
    do{
        system("cls");
        cout << "\n0. Thoat\n";
        cout << "1. Nhap Mang\n";
        cout << "2. Xuat Mang\n";
        cout << "3. Dem so luong so nguyen to\n";
        cout << "4. Sap Xep So Nguyen To\n";
        cout << "5. Xoa tat ca so nguyen to\n";
        cout << "Nhap Lua Chon Cua Ban: ";
        cin >> select;
        switch (select)
        {
        case 0: break;
        case 1:
            {
                do{
                    cout << "Nhap so luong phan tu: ";
                    cin >> n;
                    if(n < 0)
                        cout << "So luong la phai >= 0!\n";
                }while(n < 0);
                Allocation(a, n);
                input_Arr(a, n);
                break;
            }
        case 2:
            {
                output_Arr(a, n);
                break;
            }
        case 3:
            {
                cout << "So luong so nguyen to: "<<count_Prime(a, n)<<endl;
                break;
            }
        case 4:
            {
                sort_Prime(a, n);
                cout<<"Mang sau khi duoc sap xep: ";
                output_Arr(a, n);
                break;
            }
        case 5:
            {
                delete_Prime(a, n);
                cout<<"Mang sau khi xoa so nguyen to: ";
                output_Arr(a, n);
                break;
            }
        default:
            break;
        }
        system("pause");
    }while(select != 0);
    if(a != NULL)
    {
        Evict(a);
    }
    return 0;
}
