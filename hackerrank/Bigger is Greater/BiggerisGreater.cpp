#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b) {
    char c = a;
    a = b;
    b =c;
}
string biggerIsGreater(string w)
{
    int l = w.length();
    string res ="";
    bool flag = false;
    for (int i = l - 1; i > 0; i--)
    {
        if (w[i - 1] < w[i])
        {
            flag = true;
            // swap(w[i - 1], w[l - 1]);
            for(int k = l-1; k >= i; k--) {
                if(w[k] > w[i-1]) {
                    swap(w[k], w[i-1]);
                    break;
                }
            }
            for (int j = 0; j < i; j++)
            {
                res += w[j];
            }
            // cout << res;
            for (int j = l - 1; j >= i; j--)
            {
                res += w[j];
            }
            // cout << res;
            break;
        }
    }
    
    
    if(flag == false) {
        return "no answer";
    }
    return res;
}
int main()
{
    string s;
    // cin.ignore();
    // getline(cin, s);
    s = "dkhc";
    cout << biggerIsGreater(s);
}