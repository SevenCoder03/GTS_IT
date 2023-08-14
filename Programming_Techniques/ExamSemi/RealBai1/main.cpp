#include<iostream>
using namespace std;

long long cau1a(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return cau1a(n - 1) + 2*cau1a(n - 2);
}

long long cau1bi(int n)
{
	long long a[1000];
	a[0] = 1;
	a[1] = 1;
	for (long long i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + 2*a[i - 2];
    }
    return a[n];
}

long long cau1bii(int n)
{
	long long F0 = 1, F1 = 1;
	for (int i = 2; i <= n; i++)
    {
        long long tmp = F1;
        F1+=2*F0;
        F0 = tmp;
    }
	return F1;
}
// c) Trong 3 cach tren, cach thu 3 ham cau1bii toi uu hon vi:
// Toi uu ve thoi gian va khong gian bo nho
int main()
{
	int n;
	cin>>n;
	cout << cau1a(n) << endl;
	cout << cau1bi(n) << endl;
	cout << cau1bii(n) << endl;
	return 0;
}
