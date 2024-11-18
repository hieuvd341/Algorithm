<<<<<<< HEAD

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include<algorithm>
using namespace std;
vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size() / 3;
    vector<vector<int>> res;
    if (nums.size() % 3 != 0)
        return res;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (abs(nums[3 * i] - nums[3 * i + 1]) <= k &&
            abs(nums[3 * i + 2] - nums[3 * i + 1]) <= k &&
            abs(nums[3 * i] - nums[3 * i + 2]) <= k)
        {
            res.push_back({nums[3 * i], nums[3 * i + 1], nums[3 * i + 2]});
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        return res;
    }
    vector<vector<int>> tmp;
    return tmp;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int>nums;
    int k;
    inputFile >> k;
    int tmp;
    while(!inputFile.eof()){
        inputFile >> tmp;
        nums.push_back(tmp);
    }
    vector<vector<int>> res;
    res = divideArray(nums, k);
}
=======

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include<algorithm>
using namespace std;
vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size() / 3;
    vector<vector<int>> res;
    if (nums.size() % 3 != 0)
        return res;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (abs(nums[3 * i] - nums[3 * i + 1]) <= k &&
            abs(nums[3 * i + 2] - nums[3 * i + 1]) <= k &&
            abs(nums[3 * i] - nums[3 * i + 2]) <= k)
        {
            res.push_back({nums[3 * i], nums[3 * i + 1], nums[3 * i + 2]});
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        return res;
    }
    vector<vector<int>> tmp;
    return tmp;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int>nums;
    int k;
    inputFile >> k;
    int tmp;
    while(!inputFile.eof()){
        inputFile >> tmp;
        nums.push_back(tmp);
    }
    vector<vector<int>> res;
    res = divideArray(nums, k);
}
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
