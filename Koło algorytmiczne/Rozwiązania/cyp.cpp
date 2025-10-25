#include <iostream>

void multi_div2(std::string &number);

void multi_nondiv2(int index, std::string &number);

int main()
{
    int k;
    std::string number;
    std::cin >> k;

    for (int i{0}; i < k; i++)
    {
        std::cin >> number;
        
        if (number.size() == 1) //jednocyfrowa liczba
        {
            if ((number[0] - '0') % 2 == 0 && number[0] != '8') { number[0] += 2; }
            else if (number[0] == '8' || number[0] == '9') { number[0] = '2'; number += '0'; }
            else { number[0] += 1; }
        }
        else //wielocyfrowa liczba
        {
            if ((number[0] - '0') % 2 == 0) { multi_div2(number); }
            else { multi_nondiv2(0, number); }
        }
        std::cout << number << std::endl;
    }
}

void multi_div2(std::string &number)
{
    bool changed{};
    for (int j{1}; j < number.size(); j++)
    { if (number[j] % 2) {  multi_nondiv2(j, number); changed = true; } }
    if (!changed && number[number.size() - 1] != '8') { number[number.size()-1] += 2; }
    else if (!changed && number[0] != '8' && number[number.size() - 1] == '8') 
    { 
        number[0] += 2;
        for (int k{1}; k < number.size(); k++) { number[k] = '0'; }
    }
    else if (!changed && number[0] == '8' && number[number.size() - 1] == '8')
    {
        number[0] = '2';
        for (int k{1}; k < number.size(); k++) { number[k] = '0'; }
        number += '0';
    }
}

void multi_nondiv2(int index, std::string &number)
{
    if (index == 0)
    {
        if (number[index] != '9')
        {
            number[index]++;
            for (int k{index + 1}; k < number.size(); k++) { number[k] = '0'; }
        }
        else 
        { 
            number[0] = '2'; 
            for (int k{1}; k < number.size(); k++) { number[k] = '0'; }
            number += '0';
        }
    }
    else 
    {
        if (number[index] != '9')
        {
            number[index]++;
            for (int k{index + 1}; k < number.size(); k++) { number[k] = '0'; }
        }
        else
        {
            for (int k{index - 1}; k >= 0; k--)
            {
                if (number[k] != '8') 
                { 
                    number[k] += 2;
                    for (int l{k+1}; l < number.size(); l++)
                    { number[l] = '0'; } break;
                }
            }
        }
    }
    
}