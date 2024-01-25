#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string encryption(string s)
{
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        str += s[i];
    }
    int new_size = str.size();
    int row = sqrt(new_size);
    string res;
    if (row * row == new_size)
    {
        for (int i = 0; i < row; i++)
        {
            int tmp = i;
            while (tmp < new_size)
            {
                res += str[tmp];
                tmp += row;
            }
            res += ' ';
        }
    }
    else
    {
        row +=1;
        for (int i = 0; i < row; i++)
        {
            int tmp = i;
            while (tmp < new_size)
            {
                res += str[tmp];
                tmp += row;
            }
            res += ' ';
        }
    }

    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << encryption(s);

    return 0;
}