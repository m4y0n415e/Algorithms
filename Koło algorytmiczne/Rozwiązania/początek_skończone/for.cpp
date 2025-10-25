#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int main(int argc, char** argv) // lub char* argv[]
{
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }

    int ile = std::stoi(argv[1]);

    std::string in = argv[2];
    std::string out = argv[3];

    std::ifstream plik_we(in);
    std::ofstream plik_wy(out);

    if (plik_we)
    {
        plik_we.close();
    }
    if (plik_wy)
    {
        plik_wy.close();
    }

    double liczba = 2137.42069;
    std::cout << std::fixed << std::setprecision(20) << std::setw(10) << std::left << std::setfill('-') << liczba << "*" << std::endl;
}
