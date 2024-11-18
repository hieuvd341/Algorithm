#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int proc(vector<int> v, int n, int x)
{
    int size = v.size();
    auto comp = [](int a, int b)
    {
        return a > b;
    };
    int count = 0;
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < size; i++)
    {
        int temp = x / v[i];
        x = x - (temp * v[i]);
        count += temp;
    }
    if (x == 0)
    {
        return count;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n, x;
    // n = 4;
    // x = 10;
    // vector<int> v = {2, 1, 1, 3};
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << proc(v, n, x) << endl;
    return 0;
}