#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void porownanie(string a, string b);

int main()
{
	int n;

	cin >> n;

	string zak1, zak2;
	for (int i{}; i < n; i++)
	{
		cin >> zak1;
		porownanie(zak1, zak2);
	}
}

void porownanie(string a, string b)
{
	sort(a.begin(), a.end()); sort(b.begin(), b.end());

	if (a == b) { cout << "TAK"; }
	else
	{
		int i{}, ap{}, bp{};
		while (a[i] == '?')
		{
			ap++; a.erase(a.begin() + i);
		}
		while (b[i] == '?')
		{
			bp++; b.erase(b.begin(), b.end());
		}

	}

}