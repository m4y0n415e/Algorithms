#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;

	cin >> n >> m;

	long long h, g{}, c{};
	for (int i{1}; i <= n; i++)
	{
		cin >> h;
		if (h >= m) { g = i; }
		c += g;
	}

	cout << c;
}