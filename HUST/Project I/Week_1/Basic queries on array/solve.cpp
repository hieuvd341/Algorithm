#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int findMax(const vector<int> &array)
{
    int max_value = INT_MIN;
    for (int num : array)
    {
        if (num > max_value)
        {
            max_value = num;
        }
    }
    return max_value;
}

int findMin(const vector<int> &array)
{
    int min_value = INT_MAX;
    for (int num : array)
    {
        if (num < min_value)
        {
            min_value = num;
        }
    }
    return min_value;
}

int findSegmentMax(const vector<int> &array, int start, int end)
{
    int max_value = INT_MIN;
    for (int i = start; i <= end; ++i)
    {
        if (array[i] > max_value)
        {
            max_value = array[i];
        }
    }
    return max_value;
}

int findSegmentMin(const vector<int> &array, int start, int end)
{
    int min_value = INT_MAX;
    for (int i = start; i <= end; ++i)
    {
        if (array[i] < min_value)
        {
            min_value = array[i];
        }
    }
    return min_value;
}

int calculateSum(const vector<int> &array)
{
    int total = 0;
    for (int num : array)
    {
        total += num;
    }
    return total;
}

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);

    for (int &num : array)
    {
        cin >> num;
    }

    char asterisk;
    cin >> asterisk;

    string command;
    while (getline(cin, command) && command != "***")
    {
        if (command == "find-max")
        {
            cout << findMax(array) << endl;
        }
        else if (command == "find-min")
        {
            cout << findMin(array) << endl;
        }
        else if (command.find("find-max-segment") != string::npos)
        {
            int i, j;
            sscanf(command.c_str(), "find-max-segment %d %d", &i, &j);
            cout << findSegmentMax(array, i - 1, j - 1) << endl;
        }
        else if (command.find("find-min-segment") != string::npos)
        {
            int i, j;
            sscanf(command.c_str(), "find-min-segment %d %d", &i, &j);
            cout << findSegmentMin(array, i - 1, j - 1) << endl;
        }
        else if (command == "sum")
        {
            cout << calculateSum(array) << endl;
        }
    }

    return 0;
}
