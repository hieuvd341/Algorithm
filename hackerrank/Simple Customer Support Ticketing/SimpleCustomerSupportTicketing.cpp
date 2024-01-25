#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void SimpleCustomerSupportTicketing(string s)
{
    int len = s.length();
    vector<char> brackets;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            brackets.push_back(s[i]);
        }
        else if (s[i] == ')')
        {
            int size = brackets.size();
            if (size == 0)
            {
                cout << "NO" << endl;
                return;
            }
            if (brackets[size - 1] != '(')
            {
                cout << "NO" << endl;
                return;
            }
            brackets.pop_back();
        }
        else if (s[i] == '}')
        {
            int size = brackets.size();
            if (size == 0)
            {
                cout << "NO" << endl;
                return;
            }
            if (brackets[size - 1] != '{')
            {
                cout << "NO" << endl;
                return;
            }
            brackets.pop_back();
        }
        else
        {
            int size = brackets.size();
            if (size == 0)
            {
                cout << "NO" << endl;
                return;
            }
            if (brackets[size - 1] != '[')
            {
                cout << "NO" << endl;
                return;
            }
            brackets.pop_back();
        }
    }
    if (brackets.size() != 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file!";
        return 0;
    }
    int n;
    inputFile >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        inputFile >> str;
        // cout << str << endl;
        SimpleCustomerSupportTicketing(str);
    }
    return 0;
}