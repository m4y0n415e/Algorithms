#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	uint16_t k, n, m;

	std::cin >> n >> m >> k;

	std::vector<std::vector<uint32_t>> siatka(n);
	std::vector< uint32_t> sumy(m);

	uint32_t l{};
	for (uint32_t i{}; i < n; i++)
	{
		for (uint32_t j{}; j < m; j++)
		{
			l = j;
			std::cin >> siatka[i][j];
			// if (l < k)
			// {
			// 	sumy[j] += 
			// }
		}
	}
//sumy prefiksowe pon i pion

}