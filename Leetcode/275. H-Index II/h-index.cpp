#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int> &citations)
{
    int n = citations.size();

    int i = 0;
    int j = n - 1;
    int mid;

    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (citations[mid] >= (n - mid))
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return n - i;
}

int main()
{
    vector<int> citations = {0, 1, 3, 5, 6};
    sort(citations.begin(), citations.end());
    cout << hIndex(citations) << endl;
    return 0;
}