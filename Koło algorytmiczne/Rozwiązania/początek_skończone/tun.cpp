#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

int bin_search(int height, const std::vector<uint32_t>& tunnel, int s, int e);

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	uint32_t a, b, in;

	std::cin >> a >> b;

	std::vector<uint32_t> tun_h(a);

	for (uint32_t i{}; i < a; i++)
	{
		std::cin >> in;
		tun_h[i] = in;
		if (i > 0 && tun_h[i - 1] < tun_h[i])
		{
			tun_h[i] = tun_h[i - 1];
		}
	}

	in = 0;
	for (int i{}; i < b; i++)
	{
		std::cin >> in;
		std::cout << bin_search(in, tun_h, 0, a - 1) << " ";
	}
}

int bin_search(int height, const std::vector<uint32_t>& tunnel, int s, int e)
{
	int out{};
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (tunnel[m] > height)
		{
			out = m + 1;
			s = m + 1;
		}
		else { e = m - 1; }
	}
	return out;
}
