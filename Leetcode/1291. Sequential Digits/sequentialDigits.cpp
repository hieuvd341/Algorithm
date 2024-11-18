<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <Windows.h>
using namespace std;

void findSequentialDigits(vector<int> &res, int current, int low, int high, int last_digit)
{
    if (current >= low && current <= high)
    {
        res.push_back(current);
    }
    if (last_digit <= 9 && current * 10 + last_digit <= high)
    {
        findSequentialDigits(res, current * 10 + last_digit, low, high, last_digit + 1);
    }
}

vector<int> sequentialDigits(int low, int high)
{
    vector<int> res;
    for (int i = 1; i <= 9; i++)
    {
        findSequentialDigits(res, i, low, high, i + 1);
    }
    set<int> s(res.begin(), res.end());
    res.assign(s.begin(), s.end());
    return res;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }

    int low, high;
    inputFile >> low;
    inputFile >> high;

    vector<int> res = sequentialDigits(low, high);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <Windows.h>
using namespace std;

void findSequentialDigits(vector<int> &res, int current, int low, int high, int last_digit)
{
    if (current >= low && current <= high)
    {
        res.push_back(current);
    }
    if (last_digit <= 9 && current * 10 + last_digit <= high)
    {
        findSequentialDigits(res, current * 10 + last_digit, low, high, last_digit + 1);
    }
}

vector<int> sequentialDigits(int low, int high)
{
    vector<int> res;
    for (int i = 1; i <= 9; i++)
    {
        findSequentialDigits(res, i, low, high, i + 1);
    }
    set<int> s(res.begin(), res.end());
    res.assign(s.begin(), s.end());
    return res;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }

    int low, high;
    inputFile >> low;
    inputFile >> high;

    vector<int> res = sequentialDigits(low, high);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
