#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    string in = argv[1];
    string out = argv[2];
    ifstream file_in(in);
    ofstream file_out(out);

    vector<int> data(25);
    vector<int> count(41, 0);

    for (int i = 0; i < 25; ++i) {
        file_in >> data[i];
        count[data[i]]++;
    }
    file_in.close();

    vector<int> n(41, 0);
    for (int i = 40; i >= 1; --i) {
        n[i] = n[i + 1] + count[i];
    }

    for (int i = 40; i >= 1; --i) {
        cout << setw(2) << i << " " << setw(25) << right << string(n[i], '*') << endl;
    }

    return 0;
}