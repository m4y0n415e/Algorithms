#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    unsigned int n;
    std::cin >> n;

    std::vector <unsigned long long> weight(n);    
    for(int i = 0; i < n; i++)
    {
        std::cin >> weight[i];
    }

    std::vector <unsigned long long> sum(n+1);
    sum[0] = 0;

    for(int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + weight[i];
    }

    unsigned int k, w1, w2;
    unsigned long long sum_w{};
    std::cin >> k;

    for(int i = 0; i < k; i++)
    {
        std::cin >> w1 >> w2;
        sum_w = sum[w2] - sum[w1 - 1];
        std::cout << sum_w << "\n";
        sum_w = 0;
    }
}
    //brute force
//     int k, w1, w2, sum_w{}; std::cin >> k;
//     for(int i = 0; i < k; i++)
//     {
//         std::cin >> w1 >> w2;
        
//         for(int j = (w1-1); j <= (w2-1); j++)
//         {
//             sum_w+=weight[j];
//         }
//         std::cout << sum_w << "\n";
//         sum_w = 0;
//     }
