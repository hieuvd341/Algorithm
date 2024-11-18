#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <Windows.h>
using namespace std;

int sub_palindrome(string str)
{
    set<char> s;
    for (char i : str)
    {
        s.insert(i);
    }
    int len = str.length();
    int sum = 0;
    int left, right;
    map<string, int> mp;
    for (int i = 0; i < len; i++)
    {
        string left_str = "";
        string right_str = "";
        left = i;
        right = len - i - 1;

        int min_value = min(left, right);
        for (int ii = 1; ii <= min_value; ii++)
        {
            if (str[i - ii] != str[i + ii])
            {
                break;
            }
            left_str = str[i - ii] + left_str;
            right_str += str[i + ii];
            mp[left_str + str[i]]++;
            // cout << "1: " << left_str << " " <<  str[i] << " " << right_str  << endl;
        }
        for (int ii = 1; ii <= min_value+1; ii++)
        {
            if (str[i - ii] != str[i + ii - 1])
            {
                break;
            }
            left_str = str[i - ii] + left_str;
            right_str += str[i + ii - 1];
            mp[left_str]++;
            // cout << "2: " << left_str <<" "<< right_str  << endl;
        }
    }
    for (auto entry : mp)
    {
        sum++;
    }
    return sum + s.size();
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file!!" << endl;
        return 0;
    }
    string str;
    inputFile >> str;
    cout << sub_palindrome(str);
}