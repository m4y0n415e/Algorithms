#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    ifstream data("nob_in.csv");
    ofstream commands("com.sql");

    set<string> laureates_columns = { "id", "name", "knownName", "gender", "birth_date", "birth_country", "death_date", "affiliation_1" };
    set<string> prizes_columns = { "awardYear", "category", "portion", "prizeAmount", "dateAwarded", "motivation", "ind_or_org" };

    vector<pair<string, int>> columns;
    unordered_map<string, int> col_cr;
    string col = "";

    if (data.is_open())
    {
        // Reading column names
        getline(data, col);
        stringstream s(col);

        int i = 0;
        string temp;
        while (getline(s, temp, ';'))
        {
            col_cr[temp] = i; // Map column name to its index
            columns.push_back({ temp, i });
            i++;
        }

        // Filtering the needed columns
        for (auto it = columns.begin(); it != columns.end(); )
        {
            if (laureates_columns.find(it->first) == laureates_columns.end() &&
                prizes_columns.find(it->first) == prizes_columns.end())
            {
                it = columns.erase(it);
            }
            else
            {
                it++;
            }
        }

        // Parsing lines
        string stemp, temp2;
        while (getline(data, stemp))
        {
            stringstream st(stemp);
            vector<string> row(col_cr.size(), "NULL");

            int count = 0;
            while (getline(st, temp2, ';'))
            {
                if (count < row.size())
                {
                    row[count] = temp2.empty() ? "NULL" : temp2;
                }
                count++;
            }

            // Generating INSERT for Laureates table
            
            commands << "INSERT INTO Laureates (";
            bool first = true;
            for (const auto& col : columns)
            {
                if (laureates_columns.find(col.first) != laureates_columns.end())
                {
                    if (!first) commands << ", ";
                    commands << col.first;
                    first = false;
                }
            }

            commands << ") VALUES (";
            first = true;
            for (const auto& col : columns)
            {
                if (laureates_columns.find(col.first) != laureates_columns.end())
                {
                    if (!first) commands << ", ";
                    if (col.second < row.size() && row[col.second] == "NULL")
                    {
                        commands << "NULL";
                    }
                    else if (col.second < row.size())
                    {
                        commands << "'" << row[col.second] << "'";
                    }
                    


                    first = false;
                }
            }
            commands << ");\n";

            // Generating INSERT for Prizes table
            commands << "INSERT INTO Prizes (";
            first = true;
            for (const auto& col : columns)
            {
                if (prizes_columns.find(col.first) != prizes_columns.end())
                {
                    if (!first) commands << ", ";
                    commands << col.first;
                    first = false;
                }
            }

            commands << ") VALUES (";
            first = true;
            for (const auto& col : columns)
            {
                if (prizes_columns.find(col.first) != prizes_columns.end())
                {
                    if (!first) commands << ", ";
                    if (col.second < row.size() && row[col.second] == "NULL")
                    {
                        commands << "NULL";
                    }
                    else if (col.second < row.size())
                    {
                        commands << "'" << row[col.second] << "'";
                    }
                    first = false;
                }
            }
            commands << ");\n";
        }
    }

    return 0;
}

