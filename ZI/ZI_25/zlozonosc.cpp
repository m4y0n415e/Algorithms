/* Dla podanej funkcji Incr należy wykonać:
1. Obliczyć prawdopodobieństwo, że operacja inkrementacji zostanie wykonana prawidłowo
i nie wystąpi błąd przepełnienia (2 punkty).
2. Obliczyć pesymistyczną złożoność czasową funkcji przyjmując jako operację dominującą
dostęp do elementu tablicy A w wierszach 3, 4 i 8 (2 punkty).
3. Obliczyć średnią liczbę wykonanych operacji porównania (A[i] = 1) w wierszu 3 (4
punkty).
4. Obliczyć średnią liczbę wykonanych operacji przypisania (A[i] := 0) w wierszu 4 (4
punkty). 
5. Bazując na funkcji Incr przedstawić treść funkcji Decr, która dokonuje dekrementacji
liczby. Jako wynik wykonania funkcja powinna zwracać wartość true w
przypadku poprawnego wykonania operacji oraz wartość false w przypadku wystąpienia
błędu przepełnienia (3 punkty).
Należy przedstawić odpowiednie obliczenia prowadzące do końcowego wyniku. */

#include <iostream>
#include <vector>

bool incr();

int main()
{
    incr();
}

bool incr()
{
    int n;
    std::cin >> n;

    std::vector<int> A(n);

    int i{};

    while ((i < n) && (A[i] == 1))
    {
        A[i] = 0;
        i++;
    }

    for (auto el: A) { std::cout << el; }

    if (i < n) { A[i] = 1; return true; }
    else { return false; }
}