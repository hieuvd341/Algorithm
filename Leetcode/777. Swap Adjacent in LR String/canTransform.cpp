#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
using namespace std;
bool canTransform(string start, string end) {
        int i =0; 
        int j = 0;
        while(i < start.size() && j < end.size()) {
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;

            if(start[i] != end[j]) return false;
            if(start[i ] == 'R' && i >j) return false;
            if(start[i ] == 'L' && i <j) return false;
            i++; j++;
        }
        while(i < start.size() && start[i] == 'X') i++;
        while(j<end.size() && end[j]=='X') j++;
        return i==j;
    }
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    string start;
    string end;
    inputFile >> start;
    inputFile >> end;
    cout << canTransform(start, end);
}