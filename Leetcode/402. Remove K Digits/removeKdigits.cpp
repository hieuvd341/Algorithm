<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include<stack>
#include<algorithm>
#include <Windows.h>
using namespace std;
string removeKdigits(string num, int k)
{
    int size = num.size();
    stack<char> s;
    s.push(num[0]);
    for (int i = 1; i < size; i++)
    {
        while (!s.empty() && num[i] < s.top() && k > 0)
        {
            s.pop();
            k--;
        }
        if (!s.empty() || num[i] != '0')
        {
            s.push(num[i]);
        }
    }
    while (k-- > 0 && !s.empty())
    {
        s.pop();
    }
    string res;
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res == "" ? "0" : res;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    string s;
    int k;
    inputFile >> s;
    inputFile >> k;
    cout << removeKdigits(s, k);
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include<stack>
#include<algorithm>
#include <Windows.h>
using namespace std;
string removeKdigits(string num, int k)
{
    int size = num.size();
    stack<char> s;
    s.push(num[0]);
    for (int i = 1; i < size; i++)
    {
        while (!s.empty() && num[i] < s.top() && k > 0)
        {
            s.pop();
            k--;
        }
        if (!s.empty() || num[i] != '0')
        {
            s.push(num[i]);
        }
    }
    while (k-- > 0 && !s.empty())
    {
        s.pop();
    }
    string res;
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res == "" ? "0" : res;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    string s;
    int k;
    inputFile >> s;
    inputFile >> k;
    cout << removeKdigits(s, k);
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}