#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::priority_queue <int> kolejka;
	
	int n;
	std::cin >> n;

	bool k; // kategoria postaci(ksiez.lub smok)
	int w{}, p{}, pk{}; // wartosc, prog (od ktorego dana ksiez. po drodze sie oswiadcza), prog koncowej ksiez.
	for (int i{}; i < n; i ++)
	{
		std::cin >> k >> w;
		if (k)
		{
			kolejka.push(-w);
		}
		else if (!k)
		{
			p = w;
			if (i != (n - 1))
			{
				while (kolejka.size() >= p)
				{
					kolejka.pop();
				}
			}
		}
		if (i == (n - 1)) pk = p;
	}
	
	int s{}; // suma skarbu
	if (kolejka.size() < pk) std::cout << -1;
	else
	{
		while (!kolejka.empty())
		{
			s -= kolejka.top();
			kolejka.pop();
		}
		std::cout << s;
	}
}