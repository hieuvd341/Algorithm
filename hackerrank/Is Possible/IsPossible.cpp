#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;

bool isPossible(int &a, int &b, int c, int d) {
    if(a == c && b ==d) {
        return true;
    }
    if(a > c || b > d) {
        return false;
    }
    int store_a = a;
    int store_b = b;
    a = a+b;
    if(isPossible(a, b, c, d)) {
        return true;
    }
    a = store_a;
    b = a + b;
    if(isPossible(a, b, c, d)) {
        return true;
    }
    b = store_b;
    return false;
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    int a, b, c,d;
    inputFile >> a;
    inputFile >> b;
    inputFile >> c;
    inputFile >> d;

    if(isPossible(a, b, c, d)) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    return 0;
}