#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

int countUniqueSubstrings(const string &text, int L)
{
    unordered_set<string> uniqueSubstrings;

    for (int i = 0; i <= text.length() - L; ++i)
    {
        string substring = text.substr(i, L);
        uniqueSubstrings.insert(substring);
    }

    return uniqueSubstrings.size();
}

int main()
{
    ifstream ifs("pi-1million.txt");
    if (!ifs.is_open())
    {
        cout << "Error opening file\n";
        return 1;
    }

    string line;
    while (getline(ifs, line))
    {
        cout << line << endl;
    }
    string filename;
    cout << "Enter the filename containing the text: ";
    cin >> filename;

    int L;
    cout << "Enter the length of substrings: ";
    cin >> L;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    int uniqueCount = countUniqueSubstrings(text, L);
    cout << "Number of unique substrings of length " << L << ": " << uniqueCount << endl;

    return 0;
}
