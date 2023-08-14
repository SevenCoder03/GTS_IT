#include <iostream>

using namespace std;

void Allocation_Arr2D(int **&a, int row, int column)
{
    a = new int *[row];
    for(int i=0; i < row; i++)
    {
        a[i] = new int [column];
    }
}

void Evict_Arr2D(int **a, int row)
{
    for(int i=0; i<row; i++)
    {
        delete []a[i];
    }
    delete []a;
}

void input_Arr2D(int **a, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<"Nhap phan tu a["<<i<<"]["<<j<<"]: ";
            cin>>*(*(a+i)+j);
        }
    }
}

void output_Arr2D(int **a, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<*(*(a+i)+j)<<" ";
        }
        cout<<endl;
    }
}

void sort_Arr2D(int **a, int r, int c)
{
    int k = c*r;
    for(int i=0; i<k-1; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if(*(*(a+(i/c))+(i%c)) > *(*(a+(j/c))+(j%c)))
            {
                int tmp = *(*(a+(i/c))+(i%c));
                *(*(a+(i/c))+(i%c)) = *(*(a+(j/c))+(j%c));
                *(*(a+(j/c))+(j%c)) = tmp;
            }
        }
    }
}

int count_Discrimination(int **a, int r, int c)
{
    int Count = 1;
    int k = r*c;
    for(int i=1; i<k; i++)
    {
        bool Flag = true;
        for(int j = i-1; j >= 0; j--)
        {
            if(*(*(a+(i/c))+(i%c)) == *(*(a+(j/c))+(j%c)))
            {
                Flag = false;
                break;
            }
        }
        if(Flag == true)
        {
            Count++;
        }
    }
    return Count;
}

int main()
{
    int **a = nullptr;
    int column, row;
    int select;
    do{
        system("cls");
        cout << "\n0. Thoat\n";
        cout << "1. Nhap Mang\n";
        cout << "2. Xuat Mang\n";
        cout << "3. Sap xep\n";
        cout << "4. Dem phan tu phan biet\n";
        cout << "Nhap Lua Chon Cua Ban: ";
        cin >> select;
        switch (select)
        {
        case 0: break;
        case 1:
            {
                do{
                    cout << "Nhap so luong dong: ";
                    cin >> row;
                    if(row < 0)
                        cout << "So luong dong la phai >= 0!\n";
                }while(row < 0);
                do{
                    cout << "Nhap so luong cot: ";
                    cin >> column;
                    if(column < 0)
                        cout << "So luong cot la phai >= 0!\n";
                }while(column < 0);
                Allocation_Arr2D(a, row, column);
                input_Arr2D(a, row, column);
                break;
            }
        case 2: output_Arr2D(a, row, column);
                break;
        case 3:
            {
                sort_Arr2D(a, row, column);
                cout<<"Mang sau khi duoc sap xep: "<<endl;
                output_Arr2D(a, row, column);
                break;
            }
        case 4:
            {
                cout<<"So luong phan tu phan biet: "<<count_Discrimination(a, row, column)<<endl;
                break;
            }
        default:
            break;
        }
        system("pause");
    }while(select != 0);
    if(a != NULL)
    {
        Evict_Arr2D(a, row);
    }
    return 0;
}
