#include<iostream>
using namespace std;
int cau1a(int n)
{
	if (n == 1)
		return 1;
	return cau1a(n - 1)*n;
}
int cau1b(int n)
{
	int a[1000];
	a[1] = 1;
	for (int i = 2; i <= n; i++)//O(n)
		a[i] = a[i - 1] * i;
	return a[n];
}
int cau1c(int n)
{
	int p = 1;

	for (int i = 2; i <= n; i++)//O(n)
		p = p*i;
	return p;
}
// trong 3 cach tren, cach thu 3 ham cau1c toi uu hon vi:
//toi uu ve thoi gian va khong gian bo nho
int main()
{
	int n;
	cin>>n;
	cout << cau1a(n) << endl;
	cout << cau1b(n) << endl;
	cout << cau1c(n) << endl;
	cout << endl;
	return 0;
}
