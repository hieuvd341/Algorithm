#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

bool compareStrings(const string &a, const string &b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

vector<string> bigSorting(vector<string> unsorted) {
    vector<string> res;
    map<int, vector<string>> mp;

    int size = unsorted.size();

    for (int i = 0; i < size; i++) {
        mp[unsorted[i].size()].push_back(unsorted[i]);
    }

    for (auto &entry : mp) {
        sort(entry.second.begin(), entry.second.end(), compareStrings);
    }

    for (auto &entry : mp) {
        for (const string &str : entry.second) {
            res.push_back(str);
        }
    }

    return res;
}


int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "error" << endl;
        return 0;
    }
    int n;
    inputFile >> n;
    string str;
    vector<string> unsorted;
    for(int i =0;i < n; i++) {
        inputFile >> str;
        unsorted.push_back(str);
    }
    vector<string> res;
    res = bigSorting(unsorted);
    ofstream outputFile("output.txt");
    for (const string &str : res) {
        outputFile << str << endl;
    }
    outputFile.close();  // Close the file when done

}