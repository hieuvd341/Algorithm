#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;
int devide(map<char, int> mp, int i, int minLength, int maxUnique) {
    for(auto it = mp.rbegin(); it != mp.rend(); it++) {
        if(i == 0) break;
        
        i--;
    }
}
int componentGroups(string s, int minLength, int maxLength, int maxUnique) {
    int len = s.length();
    map<char, int> mp;
    for(int i = 0; i < len; i++) {
        mp[i]++;
    }
    for(int i =1; i < minLength; i++) {

    }
}


int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    string s;
    inputFile >> s;
    int minLength;
    int maxLength;
    int maxUnique;
    inputFile >> minLength;
    inputFile >> maxLength;
    inputFile >> maxUnique;

    
}