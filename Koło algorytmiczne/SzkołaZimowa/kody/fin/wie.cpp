#include <iostream>
#include <vector>

using namespace std;

int check(int wzrost, vector<int>& schodki, int p, int k);

int main()
{
	int m, n;

	cin >> n >> m;

	vector<int> schodki(n);

	int in;
	for (int i{}; i < n; i++)
	{
		cin >> in;
		schodki[i] = in + 1;
		if (i > 0 && schodki[i - 1] > schodki[i])
			schodki[i] = schodki[i - 1];
	}

	in = 0; int wyn{};
	for (int i{}; i < m; i++)
	{
		cin >> in;
		cout << check(in, schodki, 0, n - 1) << " ";
	}
}

int check(int wzrost, vector<int>& schodki, int p, int k)
{
	int m{};
	while (p <= k)
	{
		int s = (p + k) / 2;
		if (schodki[s] <= wzrost)
		{
			m = s + 1;
			p = s + 1;
		}
		else { k = s - 1; }
	}
	return m;
}
