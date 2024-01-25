#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int equal(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    int n = arr.size();
    int op1 = 0, op2 = 0, op3 = 0;
    for(int i =1; i < n ; i++) {
        int min = arr[i] - arr[0];
        op1 += min/5 + (min%5)/2 + (min%5)%2;
        op2 += (min+1)/5 + ((min + 1)%5)/2 + ((min +1)%5)%2;
        op3 += (min+2)/5 + ((min+2)%5)/2 + ((min +2)%5)%2;
    }
    return min(op1, min(op2+1, op3+1));
}


int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Error";
        return 0;
    }
    int n;
    inputFile >> n;
    
    int a;
    for(int i = 0; i < n; i++) {
        vector<int> arr;
        int size;
        inputFile >> size;
        for(int j = 0 ; j < size; j++) {
            inputFile >>a;
            arr.push_back(a);
        }
        cout << equal(arr) << endl;
    }
    inputFile.close();
    return 0;
}