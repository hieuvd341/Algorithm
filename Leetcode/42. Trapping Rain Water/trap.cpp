<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include <algorithm>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> leftMaxs;
    vector<int> rightMaxs;
    int leftMax = 0;
    int rightMax = 0;
    leftMaxs.push_back(0);
    rightMaxs.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (leftMax < height[i - 1])
        {
            leftMax = height[i - 1];
        }
        leftMaxs.push_back(leftMax);
        cout << leftMax << " ";
    }
    cout << endl;
    for (int i = n - 2; i >= 0; i--)
    {
        if (rightMax < height[i + 1])
        {
            rightMax = height[i + 1];
        }
        rightMaxs.push_back(rightMax);
    }
    reverse(rightMaxs.begin(), rightMaxs.end());
    for (int i = 0; i < rightMaxs.size(); i++)
    {
        cout << rightMaxs[i] << " ";
    }
    cout << endl;
    int ans = 0;
    int tmp;
    for (int i = 1; i <= n - 2; i++)
    {
        tmp = min(leftMaxs[i], rightMaxs[i]);
        if (height[i] < tmp)
        {
            ans += tmp - height[i];
        }
    }
    return ans;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> heights;
    while (!inputFile.eof())
    {
        int tmp;
        inputFile >> tmp;
        heights.push_back(tmp);
    }
    cout << trap(heights);
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
#include <algorithm>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> leftMaxs;
    vector<int> rightMaxs;
    int leftMax = 0;
    int rightMax = 0;
    leftMaxs.push_back(0);
    rightMaxs.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (leftMax < height[i - 1])
        {
            leftMax = height[i - 1];
        }
        leftMaxs.push_back(leftMax);
        cout << leftMax << " ";
    }
    cout << endl;
    for (int i = n - 2; i >= 0; i--)
    {
        if (rightMax < height[i + 1])
        {
            rightMax = height[i + 1];
        }
        rightMaxs.push_back(rightMax);
    }
    reverse(rightMaxs.begin(), rightMaxs.end());
    for (int i = 0; i < rightMaxs.size(); i++)
    {
        cout << rightMaxs[i] << " ";
    }
    cout << endl;
    int ans = 0;
    int tmp;
    for (int i = 1; i <= n - 2; i++)
    {
        tmp = min(leftMaxs[i], rightMaxs[i]);
        if (height[i] < tmp)
        {
            ans += tmp - height[i];
        }
    }
    return ans;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> heights;
    while (!inputFile.eof())
    {
        int tmp;
        inputFile >> tmp;
        heights.push_back(tmp);
    }
    cout << trap(heights);
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}