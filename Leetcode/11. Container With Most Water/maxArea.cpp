<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;
int maxArea(vector<int>& height) {
        int left, right;
        left =0;
        right = height.size()-1;
        int maxi = (right - left ) * min(height[left], height[right]);
        while(left < right ){
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = h * w;
            maxi = max(maxi, area);
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else {
                left++;
                right--;
            }
        }
        return maxi;
    }
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> height;
    int tmp;
    while(!inputFile.eof()) {
        inputFile >> tmp;
        height.push_back(tmp);
    }
    cout << maxArea(height);    
=======
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;
int maxArea(vector<int>& height) {
        int left, right;
        left =0;
        right = height.size()-1;
        int maxi = (right - left ) * min(height[left], height[right]);
        while(left < right ){
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = h * w;
            maxi = max(maxi, area);
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else {
                left++;
                right--;
            }
        }
        return maxi;
    }
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> height;
    int tmp;
    while(!inputFile.eof()) {
        inputFile >> tmp;
        height.push_back(tmp);
    }
    cout << maxArea(height);    
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}