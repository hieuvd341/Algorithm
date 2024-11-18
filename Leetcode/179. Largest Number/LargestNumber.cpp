<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include <string>
#include <algorithm>
using namespace std;
string largestNumber(vector<int> &nums)
{
    auto cmp = [&](int &a, int b)
    {
        return (to_string(a) + to_string(b) > to_string(b) + to_string(a));
    };
    sort(nums.begin(), nums.end(), cmp);
    string ans = "";
    for (auto it : nums)
    {
        ans += to_string(it);
    }
    return ans[0] == '0' ? "0" : ans;
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

    while (inputFile >> tmp) 
    {
        nums.push_back(tmp);
    }

    inputFile.close(); // Close the input file after reading

    cout << largestNumber(nums);

    return 0;
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include <string>
#include <algorithm>
using namespace std;
string largestNumber(vector<int> &nums)
{
    auto cmp = [&](int &a, int b)
    {
        return (to_string(a) + to_string(b) > to_string(b) + to_string(a));
    };
    sort(nums.begin(), nums.end(), cmp);
    string ans = "";
    for (auto it : nums)
    {
        ans += to_string(it);
    }
    return ans[0] == '0' ? "0" : ans;
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

    while (inputFile >> tmp) 
    {
        nums.push_back(tmp);
    }

    inputFile.close(); // Close the input file after reading

    cout << largestNumber(nums);

    return 0;
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}