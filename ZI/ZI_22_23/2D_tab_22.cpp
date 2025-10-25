#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    int **tab = new int*[n];

    int l;
    for(int i{}; i < n; i++)
    {
        tab[i] = new int[n];
    }
}