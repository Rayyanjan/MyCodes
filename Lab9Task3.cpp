#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

string toLower(const string &str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
              [](unsigned char c)
              { return tolower(c); });
    return lowerStr;
}

string removePunctuation(const string &str)
{
    string result;
    for (char c : str)
    {
        if (isalnum(c) || c == ' ')
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    ifstream ifs("ok.txt"); // assuming input.txt is in the current directory
    if (!ifs.is_open())
    {
        cout << "Error opening file\n";
        return 1;
    }
    // ifs can be used like cin
    // e.g. int x; ifs >> x; // read an integer from file
    string line;
    while (getline(ifs, line))
    {
        cout << line << endl;
    }

    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    int lineNumber = 0;
    map<string, vector<int>> index;

    while (getline(file, line))
    {
        ++lineNumber;

        line = toLower(line);
        line = removePunctuation(line);

        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            index[word].push_back(lineNumber);
        }
    }

    for (const auto &entry : index)
    {
        cout << entry.first << " ";
        const vector<int> &lines = entry.second;
        auto range = minmax_element(lines.begin(), lines.end());
        if (range.first != lines.end())
        {
            cout << *range.first;
            if (range.first != range.second)
            {
                cout << "-" << *range.second;
            }
        }
        cout << endl;
    }

    return 0;
}
