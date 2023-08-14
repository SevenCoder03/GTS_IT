#include <iostream>

using namespace std;

int main()
{
	double km;
	cout << "Nhap so km: ";
	cin >> km;

	long long sotien = 0;

	if (km <= 1)
	{
		sotien = km * 15000;
	}
	else
	{
		if (km <= 5)
		{
			sotien = 15000 + (km - 1) * 13500;
		}
		else
		{
			sotien = 15000 + 4 * 13500 + (km - 5) * 10000;

			if (km > 120)
			{
				sotien = sotien *0.9;
			}
		}
	}
    cout<<sotien;
	return 0;
}

