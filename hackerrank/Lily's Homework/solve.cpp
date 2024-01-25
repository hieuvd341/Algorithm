#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

void swap(int &a, int &b) {
    int c =a;
    a = b;
    b = c;
}
int lilysHomework(vector<int> arr) {
    vector<pair<int,int>> parr1;
    vector<pair<int,int>> parr2;
    for (long i = 0; i < arr.size(); i++)
        parr1.push_back({arr[i],i});    
    for (long i = 0; i < arr.size(); i++)
        parr2.push_back({arr[i],i});
    sort(parr1.begin(),parr1.end());
    sort(parr2.rbegin(),parr2.rend());
    int counta = 0; int countd = 0;  
    for (long i = 0; i < parr1.size(); i++){
        while(arr[i]!=parr1[i].first){
            swap(parr1[i],parr1[parr1[i].second]);
            counta++;
        }
    }
    for (long i = 0; i < parr2.size(); i++){
        while (arr[i] != parr2[i].first){
            swap(parr2[i],parr2[parr2[i].second]);
            countd++;
        }    
    }
    int result = 0;
    if (counta < countd){result = counta;}
    else {result = countd;}
    return result;
}

int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Error!!";
        return 0;
    }
    int n;
    inputFile >> n;
    vector<int> arr(n);
    for(int i =0; i < n ; i ++) {
        inputFile >> arr[i];
    }
    inputFile.close();
    cout << lilysHomework(arr);
}