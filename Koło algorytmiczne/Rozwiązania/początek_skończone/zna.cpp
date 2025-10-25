#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    unsigned int n, m;

    std::set <unsigned int> z_bitek;
    unsigned int z1, z2;

    std::cin >> n >> m;

    for (unsigned int i = 0; i < n; i++)
    {
        std::cin >> z1;
        z_bitek.insert(z1);
    }

    unsigned int size = z_bitek.size(), fin_value{};
    for (unsigned int i = 0; i < m; i++)
    {
        std::cin >> z2;
        z_bitek.insert(z2);
        if(z_bitek.size() > size)
        {
            fin_value++;
            size = z_bitek.size();
        }
    }

    std::cout << fin_value;
}