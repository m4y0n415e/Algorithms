#include <iostream>

int main()
{
	int liczba = 1, max = 0, suma{};
	do
	{
		std::cin >> liczba;
		if (liczba < 0) {
			if (max < suma)
			{
				max = suma;
			}
			suma = 0;
		}
		else {
			suma += liczba;
			if (suma > max)
			{
				max = suma;
			}
		}
	} while (liczba != 0);
	std::cout << max;
}
