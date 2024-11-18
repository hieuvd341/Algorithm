<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long candies(int n, vector<int> arr)
{
    long long sum = 0;
    vector<int> visit(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            visit[i] = visit[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && visit[i] <= visit[i + 1])
        {
            visit[i] = visit[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += visit[i];
        // cout << sum << endl;
    }
    return sum;
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
    vector<int> v;
    int a;

    for (int i = 0; i < n; i++)
    {
        inputFile >> a;
        v.push_back(a);
    }
    
    cout << candies(n, v) ;
    return 0;
=======
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long candies(int n, vector<int> arr)
{
    long long sum = 0;
    vector<int> visit(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            visit[i] = visit[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && visit[i] <= visit[i + 1])
        {
            visit[i] = visit[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += visit[i];
        // cout << sum << endl;
    }
    return sum;
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
    vector<int> v;
    int a;

    for (int i = 0; i < n; i++)
    {
        inputFile >> a;
        v.push_back(a);
    }
    
    cout << candies(n, v) ;
    return 0;
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}