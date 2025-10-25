#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned int n, k;
	cin >> n >> k;

	vector<int> h(n);
	for (int i{}; i < n; i++)
	{
		cin >> h[i];
	}

	int maxli = 1, p = 0, l = 0;
	unsigned int kred = k;

	while (p < (n - 1))
	{
		p++;
		if (h[p] > h[p - 1])
		{
			unsigned int koszt = h[p] - h[p - 1];
			if (koszt <= kred) 
			{
				kred -= koszt;
			}
			else 
			{
				while (kred < koszt && l < p) 
                {
                    if (h[l] < h[l + 1]) 
                    {
                        kred += h[l + 1] - h[l];  
                    }
                    l++;  
				}
				kred -= koszt;
			}
		}
		maxli = max(maxli, p - l + 1);
	}

	cout << maxli;
}