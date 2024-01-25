#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }

    
}