#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::set<int> out;
    std::string nazwa1 = argv[1], nazwa2 = argv[2];
    std::fstream plik1(nazwa1), plik2(nazwa2);

    int liczba1{}, liczba2{};
    while (plik1 >> liczba1)
    {
        while(plik2 >> liczba2)
        {
            if(liczba1 == liczba2)
            out.insert(liczba1);
        }
    }

    std::set<int>::iterator p;

    if(out.size()!=0)
    {
        for(p=out.begin(); p != out.end(); p++)
        {
            std::cout << *p << "\n";
        }
    } else { std::cout  << "BRAK ROZWIAZANIA"; }
}