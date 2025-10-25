#include <iostream>
#include <vector>

void not_vis(int index, std::vector<int>& uklad, int size, bool *vis, int& count);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> uklad(n);

    for (int i = 0; i < n; i++) {
        std::cin >> uklad[i];
    }

    bool *vis = new bool[n];
    int stoliki{}, index{};

    for (int i = 0; i < n; i++) 
    {
        if(vis[i] == false) {
            not_vis(i, uklad, n, vis, stoliki);
        }
    }
    delete [] vis;

    std::cout << stoliki;
}

void not_vis(int index, std::vector<int>& uklad, int size, bool *vis, int& count) {
            vis[index] = true;
            while (vis[uklad[index] - 1] == false) { 
                vis[uklad[index] - 1] = true;
                index = uklad[index] - 1;
            } count++;
}