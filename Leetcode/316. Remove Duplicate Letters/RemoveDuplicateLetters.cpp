#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <stack>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>
using namespace std;

string removeDuplicateLetters(string str)
{
    vector<int> lastIndex(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        lastIndex[str[i] - 'a'] = i;
    }
    vector<bool> seen(26, false);
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        int curr = str[i] - 'a';
        if (seen[curr])
            continue;
        while (st.size() > 0 && st.top() > str[i] && i < lastIndex[st.top() - 'a'])
        {
            seen[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(str[i]);
        seen[curr] = true;
    }
    string ans = "";
    while (st.size() > 0)
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    inputFile >> s;
    cout << removeDuplicateLetters(s);
}