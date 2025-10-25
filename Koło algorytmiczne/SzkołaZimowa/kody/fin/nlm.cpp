#include <iostream>
#include <vector>

using namespace std;

int search(int w, vector<bool>& visited, vector<vector<int>>& connections);

int main()
{
    unsigned int n;
    cin >> n;

    vector<vector<int>> connections(n);

    for (int i{}; i < (n - 1); i++)
    {
        int a, b;
        cin >> a >> b;
        connections[a - 1].push_back(b - 1);
        connections[b - 1].push_back(a - 1);
    }

    vector<bool> visited(n);

    int a{}, dl{};

    for (int i{}; i < n; i++)
    {
        if (connections[i].size() == 1)
        {
            a = search(i, visited, connections);
            dl = a > dl ? a : dl;
        }
    }
    cout << dl - 1;
}

int search(int w, vector<bool>& visited, vector<vector<int>>& connections)
{
    visited[w] = true;

    int max{}, b{};
    for (int i{}; i < connections[w].size(); i++)
    {
        if (!visited[connections[w][i]])
        {
            b = search(connections[w][i], visited, connections);
            max = b > max ? b : max;
        }
    }
    return max + 1;
}
