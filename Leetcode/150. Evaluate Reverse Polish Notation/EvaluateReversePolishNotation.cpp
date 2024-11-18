<<<<<<< HEAD
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


long evalRPN(vector<string> &tokens) {
    vector<long> stack;
    for (const auto &token : tokens) {
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            stack.push_back(stol(token));
        } else {
            long second = stack.back();
            stack.pop_back();
            long first = stack.back();
            stack.pop_back();

            if (token == "+") {
                stack.push_back(first + second);
            } else if (token == "-") {
                stack.push_back(first - second);
            } else if (token == "*") {
                stack.push_back(first * second);
            } else if (token == "/") {
                if (second == 0) {
                    throw std::runtime_error("Division by zero");
                }
                stack.push_back(first / second);
            }
        }
    }

    return stack.back();
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    string tmp;
    vector<string> tokens;
    while(!inputFile.eof()){
        inputFile >>tmp;
        tokens.push_back(tmp);
    }
    cout << evalRPN(tokens);
=======
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


long evalRPN(vector<string> &tokens) {
    vector<long> stack;
    for (const auto &token : tokens) {
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            stack.push_back(stol(token));
        } else {
            long second = stack.back();
            stack.pop_back();
            long first = stack.back();
            stack.pop_back();

            if (token == "+") {
                stack.push_back(first + second);
            } else if (token == "-") {
                stack.push_back(first - second);
            } else if (token == "*") {
                stack.push_back(first * second);
            } else if (token == "/") {
                if (second == 0) {
                    throw std::runtime_error("Division by zero");
                }
                stack.push_back(first / second);
            }
        }
    }

    return stack.back();
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    string tmp;
    vector<string> tokens;
    while(!inputFile.eof()){
        inputFile >>tmp;
        tokens.push_back(tmp);
    }
    cout << evalRPN(tokens);
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}