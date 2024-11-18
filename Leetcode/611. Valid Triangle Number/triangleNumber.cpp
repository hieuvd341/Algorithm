<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <Windows.h>
using namespace std;
int triangleNumber(vector<int> &nums)
{
    sort(begin(nums), end(nums));
    int lb;
    int count = 0;
    int ni = nums.size() - 2;
    int nj = nums.size() - 1;
    for (int i = 0; i < ni; i++)
    {
        for (int j = i + 1; j < nj; j++)
        {
            lb = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
            count += lb - j - 1;
        }
    }
    return count;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> nums;
    int tmp;
    while (!inputFile.eof())
    {
        inputFile >> tmp;
        nums.push_back(tmp);
    }
    cout << triangleNumber(nums);
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <Windows.h>
using namespace std;
int triangleNumber(vector<int> &nums)
{
    sort(begin(nums), end(nums));
    int lb;
    int count = 0;
    int ni = nums.size() - 2;
    int nj = nums.size() - 1;
    for (int i = 0; i < ni; i++)
    {
        for (int j = i + 1; j < nj; j++)
        {
            lb = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
            count += lb - j - 1;
        }
    }
    return count;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> nums;
    int tmp;
    while (!inputFile.eof())
    {
        inputFile >> tmp;
        nums.push_back(tmp);
    }
    cout << triangleNumber(nums);
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}