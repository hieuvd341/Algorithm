<<<<<<< HEAD
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int portfolioBalances(vector<vector<int>> rounds, int n) {
    vector<int> array (n+2, 0);
    for(int i =0; i < rounds.size(); i ++) {
        array[rounds[i][0]] += rounds[i][2];
        array[rounds[i][1] +1] -= rounds[i][2];
    }
    int res = 0;
    int max = 0;
    for(int i =1; i <= n+1; i++) {
        res += array[i];
        if(res > max) {
            max = res;
        }
    }
    return max;
}

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr << "Can not open file";
        return 1;
    }
    int n;
    inputFile >> n;
    vector<vector<int>> rounds;
    int row, col;
    inputFile >> row;
    int a;
    inputFile >> col;
    for(int i =0; i < row; i++){
        vector<int>v;
        for(int ii =0; ii<col; ii++) {
            inputFile >> a;
            v.push_back(a);
        }
        rounds.push_back(v);
    }
    cout << portfolioBalances(rounds, n);

=======
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int portfolioBalances(vector<vector<int>> rounds, int n) {
    vector<int> array (n+2, 0);
    for(int i =0; i < rounds.size(); i ++) {
        array[rounds[i][0]] += rounds[i][2];
        array[rounds[i][1] +1] -= rounds[i][2];
    }
    int res = 0;
    int max = 0;
    for(int i =1; i <= n+1; i++) {
        res += array[i];
        if(res > max) {
            max = res;
        }
    }
    return max;
}

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr << "Can not open file";
        return 1;
    }
    int n;
    inputFile >> n;
    vector<vector<int>> rounds;
    int row, col;
    inputFile >> row;
    int a;
    inputFile >> col;
    for(int i =0; i < row; i++){
        vector<int>v;
        for(int ii =0; ii<col; ii++) {
            inputFile >> a;
            v.push_back(a);
        }
        rounds.push_back(v);
    }
    cout << portfolioBalances(rounds, n);

>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}