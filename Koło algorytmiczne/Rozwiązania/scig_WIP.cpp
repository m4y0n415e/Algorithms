#include <iostream>
#include <cstdint>
#include <vector>

const uint32_t p = 31;

const uint32_t m = 1e9 + 9;

bool check{};

void phrase_hash(std::string phrase, std::vector<uint64_t> &tab, uint64_t m_hash);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    uint8_t n; std::string maxim;
    
    std::cin >> n;

    std::cin >> maxim;

    uint32_t pow = 1; uint64_t m_hash{};
    //hashowanie wyrazenia podanego z klawiatury
    for (uint32_t i{}; i < maxim.length(); i++)
    {
        m_hash += (m_hash + (maxim[i] - 'A' + 1) * pow) % m;
        pow = (pow * p) % m;
    }

    std::vector <uint64_t> hashed_s; //check - czy w zahashowanej maksymie wystąpił pod-wyraz
    std::string w_t_c;

    //podanie wyrazu do sprawdzenia -- czy wystepuje w maksymie
    for (uint8_t i{}; i < n; i++)
    {
        std::cin >> w_t_c;
        phrase_hash(w_t_c, hashed_s, m_hash); 
        if (check) { std::cout << "TAK" << "\n"; }
        else { std::cout << "NIE" << "\n"; }
    }
}

void phrase_hash(std::string phrase, std::vector<uint64_t> &tab, uint64_t m_hash)
{
    uint32_t pow = 1; uint64_t temp{};
    for (uint32_t i{}; i < phrase.length(); i++)
    {
        temp = ((phrase[i] - 'A' + 1) * pow ) % m;
        tab.push_back(temp);
        if (i > 2)
        {
            if (m_hash == tab[i] / p) { check = true; }
        }
        pow = (pow * p) % m;
    }
}