#include <iostream>

using namespace std;

long long suma_art(const int n);

long long suma_geo(int n);

int main()
{
	int z, n;

	cin >> z;

	for (int i{}; i < z; i++)
	{
		cin >> n;
		cout << suma_art(n) - (2 * suma_geo(n)) << "\n";
	}
}

long long suma_art(const int n)
{
	long long a = 1 + (n - 1) * 1;
	long long s = ((1 + a) * n) / 2;
	return s;
}

long long suma_geo(int n)
{
	int w{}, q = 1;

	while (n >>= 1) w++;
	q = 1 << w + 1; 

	long long s = 1 * ((1 - q) / (1 - 2));
	return s;
}
