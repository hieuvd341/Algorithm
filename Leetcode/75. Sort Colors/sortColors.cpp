<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int count_0=0;
    int count_1=0;
    int count_2=0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count_0++;
        }
        else if (nums[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }
    int i;
    for (i = 0; i < count_0; i++)
    {
        nums[i] = 0;
    }
    for (; i < count_0 + count_1; i++)
    {
        nums[i] = 1;
    }
    for (; i < count_0 + count_1 + count_2; i++)
    {
        nums[i] = 2;
    }
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
    while(!inputFile.eof()) {
        int tmp;
        inputFile >> tmp;
        nums.push_back(tmp);
    }
    sortColors(nums);
    for(int i =0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int count_0=0;
    int count_1=0;
    int count_2=0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count_0++;
        }
        else if (nums[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }
    int i;
    for (i = 0; i < count_0; i++)
    {
        nums[i] = 0;
    }
    for (; i < count_0 + count_1; i++)
    {
        nums[i] = 1;
    }
    for (; i < count_0 + count_1 + count_2; i++)
    {
        nums[i] = 2;
    }
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
    while(!inputFile.eof()) {
        int tmp;
        inputFile >> tmp;
        nums.push_back(tmp);
    }
    sortColors(nums);
    for(int i =0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}