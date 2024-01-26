#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
using namespace std;

int available(vector<int> arrival, int j, vector<int> finish, int &current)
{
    for (int i = 0; i < finish.size(); i++)
    {
        if (arrival[j] >= finish[(current + i) % (finish.size())])
        {
            current = (current + i) % (finish.size());
            return current;
        }
    }
    return -1;
}
int loadDistribution(vector<int> arrival, vector<int> load, int k)
{
    vector<int> finish(k, 0);
    vector<int> busy(k, 0);
    int current = 0;
    for (int i = 0; i < arrival.size(); i++)
    {
        int res = available(arrival, i, finish, current);
        if (res != -1)
        {
            finish[res] = arrival[i] + load[i] - 1;
            busy[res]++;
            for (int j = 0; j < finish.size(); j++)
            {
                cout << finish[j] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "drop" << endl;
        }
    }
    int busiest = INT_MIN;
    for (int j = 0; j < busy.size(); j++)
    {
        if(busiest < busy[j]) {
            busiest = busy[j];
        }
    }
    return busiest+1;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }

    int k;
    inputFile >> k;
    int arrival_size;
    inputFile >> arrival_size;
    vector<int> arrival;
    int tmp;
    for (int i = 0; i < arrival_size; i++)
    {
        inputFile >> tmp;
        arrival.push_back(tmp);
    }
    vector<int> load;
    int load_size;
    inputFile >> load_size;
    for (int i = 0; i < load_size; i++)
    {
        inputFile >> tmp;
        load.push_back(tmp);
    }
    cout << loadDistribution(arrival, load, k);
}