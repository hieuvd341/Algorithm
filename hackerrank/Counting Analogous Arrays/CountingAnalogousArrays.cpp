#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;

int countingAnalogousArrays(vector<int> array, int lowerBound, int upperBound) {
    vector<int> gadget;
    int sum = 0;

    int min_gadget = INT_MAX;
    int max_gadget = INT_MIN;
    for(int i =0; i < array.size(); i++) {
        sum += array[i];
        if(max_gadget < sum) {
            max_gadget = sum;
        }
        if(min_gadget > sum) {
            min_gadget = sum;
        }
        gadget.push_back(sum);
    }
    int count = 0;
    for(int j = lowerBound; j <= upperBound; j++) {
        if(j - min_gadget <= upperBound  && j - max_gadget >= lowerBound) {
            count++;
        }
    }
    return count;
}

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }

    int n;
    inputFile >> n;
    vector<int> array;
    int a;
    for(int i = 0; i < n; i ++) {
        inputFile >> a;
        array.push_back(a);
    }
    int lowerBound;
    int upperBound;
    inputFile >> lowerBound;
    inputFile >> upperBound;
    cout << countingAnalogousArrays(array, lowerBound, upperBound);
}