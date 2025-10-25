//WIP
#include <iostream>

using namespace std;

int suma(int n);

bool konw(int liczba, int &j);

int main()
{
	int z, n;

	cin >> z;

	for (int i{}; i < z; i++)
	{
		cin >> n;
		cout << suma(n);
	}
}

int suma(int n) 
{
	int s = -3, jedynka{};
	bool b;
	
	for (int i{3}; i < n; i++)
	{
		if (!(i % 2))
		{
			b = konw(i, jedynka);
			//cout << "\nb: " << b;
			if (!b)
				s += i;
			else s -= i;
		}
		else
		{
			s += i;
		}
	}
	return s;
}

bool konw(int liczba,int &j)
{
	if (liczba > 0)
	{
		if (liczba % 2) j++;
		if (j > 1) return false;
		else konw(liczba / 2, j);
	}
	else if (liczba == 0) return true;
}