#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minChanges(string s)
{
    int size = s.size();
    vector<int> track;
    int count = 1;
    for(int i = 1; i < size; i++)
    {
        if(s[i] == s[i-1])
        {
            count++;
        }
        else
        {
            track.push_back(count);
            count = 1;
        }
    }
    if(count != 0) track.push_back(count);
    int res = 0;

    for(int i = 0; i < track.size()-1; i++)
    {
        if(track[i]  % 2 == 1){
            res++;
            track[i+1]++;
        }
    }
    return res;
}
int main()
{
    string s;
    s = "0000";
    cout << minChanges(s);
}