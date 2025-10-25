#include <iostream>
#include <string>
#include <vector>

const int p = 31;
const int m = 1e9 + 9;

int hash(std::string name);

int main()
{
    int n;
    std::cin >> n;

    std::string name;
    std::vector <int> tanks_hashed;

    for (int i = 0; i < n; i++)
    {
        std:: cin >> name;
        tanks_hashed.push_back(hash(name));
    }

    int same_names{};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tanks_hashed[i]==tanks_hashed[j])
            {
                same_names++;
            }
        }
        
    }

    std::cout << same_names;
}

int hash(std::string name)
{
    int n_h{}, pow = 1;
    int length = name.length();
    for (int i = 0; i < length; i++)
    {
        n_h += (n_h + (name[i] - 'a' + 1) * pow) % m;
        pow = (pow * p) % m;
    }
    return n_h;
}