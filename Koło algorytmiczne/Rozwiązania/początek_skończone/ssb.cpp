#include <iostream>
#include <string>

int main()
{
    int n, m;
    std::cin >> n >> m;

    int ll = 0, lm = 1;  // Lewa granica (0/1)
    int pl = 1, pm = 0; // Prawa granica (1/0)
    int licz = 1, mian = 1; // Początek drzewa (1/1) -- licznik oraz mianownik

    std::string wynik = "";

    while (licz != n || mian != m) 
    {
        if (n * mian < m * licz) 
        {
            wynik += 'L'; pl = licz; pm = mian;
        } 
        else 
        {
            wynik += 'P'; ll = licz; lm = mian;
        }
        licz = ll + pl;
        mian = lm + pm;
    }

    std::cout << wynik << "\n";
}