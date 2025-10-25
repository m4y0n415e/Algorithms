#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int m, n;

	std::cin >> m >> n; // wielkosc ladowni i liczba plyt

	int war, wys;
	std::pair<int, int> w;

	std::priority_queue<std::pair<int, int>> plyty;

	for (int i{}; i < n; i++)
	{
		std::cin >> war >> wys;
		if (wys <= m)
		{
			w = { wys, war };
			plyty.push(w);
		}
	}

	int i = 1, ost_wys, suma_w;
	while (i <= 10)
	{
		if (ost_wys == plyty.top().first)
		{
			if 
		}
		else
		{
			ost_wys = plyty.top().first;
		}

	}
}