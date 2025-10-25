#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    string in = argv[0];
    ifstream file_in(in);

    string out = "output_" + in.substr(6);
    ofstream file_out(out);

    vector<int> data(25);
    vector<int> count(41, 0);

    for (int i = 0; i < 25; i++) 
    {
        file_in >> data[i];
        count[data[i]]++;
    }
    file_in.close();

    vector<int> n(41, 0);
    for (int i = 40; i >= 1; i--) 
    {
        n[i] = count[i] + (i < 40 ? n[i + 1] : 0);
    }

    for (int i = 40; i >= 1; i--) 
    {
        file_out << setw(2) << i << " " << setw(25) << right << string(n[i], '*') << endl;
    }

    return 0;
}