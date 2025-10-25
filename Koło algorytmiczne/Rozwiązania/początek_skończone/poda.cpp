#include <iostream>

int main()
{
    long long n;
    std::cin >> n;
		
    bool podz = false, pierwsza = false;

    if (n >= 2) pierwsza = true;

    for (long long i = 3; i * i <= n; i ++)    
    {
        if (!(n % i)) 
        {
            pierwsza = false; break;
            podz = true;
        }
    }

    if (pierwsza) 
    { 
        std::cout << "1"; podz = true;
    }
    else if  (!(n % 2)) 
    { 
        std::cout << "2"; podz = true;
    }
    else 
    {
        bool pierwsza_min_2 = true;

        for (long long i = 3; i * i <= n - 2; i += 2) 
        {
            if (!((n - 2) % i)) 
            {
                pierwsza_min_2 = false; break;
            }
        }

        if (pierwsza_min_2) 
        { 
            std::cout << "2"; podz = true;
        }
    }

    if (!podz) std::cout << "3";
}