#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b, c, k;
    int tmp;

    for (int l = 0; l < n; l++)
    {
        cin >> b;
        cin >> c;
        cin >> k;
        vector<int> v_b;
        vector<int> v_c;
        for (int i = 0; i < b; i++)
        {
            cin >> tmp;
            v_b.push_back(tmp);
        }
        for (int i = 0; i < c; i++)
        {
            cin >> tmp;
            v_c.push_back(tmp);
        }
        int count = 0;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (v_b[i] + v_c[j] <= k)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}