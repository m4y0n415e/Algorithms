#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    std::map<long long, long> licznik;

    long long el = 1;
    while (el != 0) {
        std::cin >> el;
        licznik[el]++;
    }

    long max_licznik{1};
    long long el_najc{};
    for (auto it = licznik.begin(); it != licznik.end(); it++)
    {
        if (it->second > max_licznik)
        {
            max_licznik = it->second;
            el_najc = it->first;
            //std::cout << el_najc << std::endl;
        }else  if (it->second == max_licznik && it->first > el_najc)
            {
                el_najc = it->first;
            }
    }

    std::cout << el_najc;
}
