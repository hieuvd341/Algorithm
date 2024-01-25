#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool passwordCrackerHelper(const vector<string>& passwords, const string& loginAttempt, size_t start, string& result, vector<int>& dp) {
    if (start == loginAttempt.size()) {
        return true; 
    }
    if (dp[start] == 0) return false; 

    for (const string& password : passwords) {
        size_t len = password.length();
        if (loginAttempt.substr(start, len) == password) {
            string nextResult = result.empty() ? password : result + " " + password;
            if (passwordCrackerHelper(passwords, loginAttempt, start + len, nextResult, dp)) {
                result = nextResult;
                return true;
            }
        }
    }
    
    dp[start] = 0; 
    return false;
}

string passwordCracker(vector<string> passwords, string loginAttempt) {
    string result;
    vector<int> dp(loginAttempt.size(), -1); // Use to memoize states we've visited
    if (passwordCrackerHelper(passwords, loginAttempt, 0, result, dp)) {
        return result;
    } else {
        return "WRONG PASSWORD";
    }
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt", std::ios::app);
    if (!inputFile.is_open())
    {
        cerr << "Can not open file!";
        return 0;
    }
    int numberOfTest;
    int arr_size;
    inputFile >> numberOfTest;
    inputFile >> arr_size;
    vector<string> inputs;
    string loginAttempt;
    string input;
    for (int i = 0; i < numberOfTest; i++)
    {
        for (int ii = 0; ii < arr_size; ii++)
        {
            inputFile >> input;
            inputs.push_back(input);
        }
        inputFile >> loginAttempt;
        outputFile << passwordCracker(inputs, loginAttempt) << endl;
    }
    inputFile.close();
    outputFile.close();
}