#include<iostream>
using namespace std;

void input_Arr(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> *(a + i);
    }
}

void output_Arr(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    cout<<endl;
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

void add_Arr(int *&a, int &n, int Value, int pos)
{
    resize_Arr(a, n, n++);
    for(int i = n - 1; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = Value;
}

void delete_Arr(int *&a, int &n, int pos)
{
    for(int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    resize_Arr(a, n, n--);
}

bool check_Prime(int x)
{
    if(x < 2)
        return false;
    for(int i = 2; i*i<=x; i++)
    {
        if(x % i == 0)
        {
            return false;
        }
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
int main()
{
    int *a = nullptr;
    int n = 0;
    int select;
    do{
        system("cls");
        cout << "\n0. Thoat\n";
        cout << "1. Nhap Mang\n";
        cout << "2. Xuat Mang\n";
        cout << "3. Xoa Phan Tu\n";
        cout << "4. Them Phan Tu\n";
        cout << "5. Dem So Nguyen To\n";
        cout << "6. Sap Xep So Nguyen To\n";
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
                a = new int[n];
                input_Arr(a, n);
                break;
            }
        case 2: output_Arr(a, n);
                break;
        case 3:
            {
                int pos;
                do
                {
                    cout << "Nhap vi tri muon xoa: ";
                    cin >> pos;
                    if(pos < 0 || pos >= n)
                        cout << "Vi tri khong ton tai. Nhap lai\n";
                }while(pos < 0 || pos >= n);
                delete_Arr(a, n, pos);
                break;
            }
        case 4:
            {
                int Value, pos;
                cout << "Nhap phan tu can them: ";
                cin >> Value;
                do
                {
                    cout << endl << "Ban muon them vao vi tri nao: ";
                    cin >> pos;
                    if(pos < 0 || pos > n)
                        cout << "Vi tri khong ton tai. Nhap lai\n";
                }while(pos < 0 || pos > n);
                add_Arr(a, n, Value, pos);
                break;
            }
        case 5:
            {
                cout<<"So luong so nguyen to la: "<<count_Prime(a, n)<<endl;
                break;
            }
        case 6:
            {
                sort_Prime(a, n);
                cout<<"Mang sao khi duoc sap xep: ";
                output_Arr(a, n);
            }
        default:
            break;
        }
        system("pause");
    }while(select != 0);
    if(a != NULL)
    {
        delete[] a;
    }
    return 0;
}
