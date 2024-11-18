<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<fstream>
using namespace std;

tuple<string, int, int> extract(string s) {
    tuple<string, int, int> tp;
    string tmp = s.substr(0, 3);
    if(tmp == "pop") {
        tp = make_tuple("pop", 0, 0);
    }
    else if(tmp == "inc") {
        int i = 4;
        tmp = "";
        while(s[i] != ' ') {
            tmp += s[i];
            i++;
        }        
        int number1 = stoi(tmp);
        tmp = "";
        i++;
        while(s[i] != ' '  && s[i] != '\0')  {
            tmp += s[i];
            i++;
        }        
        int number2 = stoi(tmp);
        tp = make_tuple("inc", number1, number2);
    }
    else {
        int i = 5;
        tmp = "";
        while(s[i] != ' ' && s[i] != '\0') {
            tmp += s[i];
            i++;
        }        
        int number = stoi(tmp);
        tp = make_tuple("push", number, 0);
    }
    // cout << get<0>(tp) << " " << get<1>(tp) << " " << get<2>(tp) << endl;
    return tp;
}

void push(vector<int> &v, int x) {
    v.push_back(x);
}
void pop(vector<int> &v) {
    v.pop_back();
}
void inc(vector<int> &v, int x, int y) {
    for(int i =0; i < x; i ++) {
        v[i] += y;
    }
}
void show(vector<int> v) {
    int n = v.size();
    if(n == 0) {
        cout << "EMPTY" <<endl;;
    }else {
        cout << v[n-1] << endl;
        // for(int i =0; i < n; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }
}
void superStack(vector<string> operations, int n) {
    vector<int> v;
    tuple<string, int, int> tp;
    for(string str : operations) {
        tp = extract(str);
        if(get<0>(tp) == "pop") {
            pop(v);
            show(v);
        }
        else if(get<0>(tp) == "inc") {
            inc(v, get<1>(tp), get<2>(tp));
            show(v);
        }
        else {
            push(v, get<1> (tp));
            show(v);
        }
    }
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file!";
        return 0;
    }
    vector<string> operations;
    int n;
    inputFile >> n;
    inputFile.ignore();
    for(int i =0; i < n; i++) {
        string s;
        getline(inputFile, s);
        operations.push_back(s);
    }
    superStack(operations, n);
    return 0;
=======
#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include<fstream>
using namespace std;

tuple<string, int, int> extract(string s) {
    tuple<string, int, int> tp;
    string tmp = s.substr(0, 3);
    if(tmp == "pop") {
        tp = make_tuple("pop", 0, 0);
    }
    else if(tmp == "inc") {
        int i = 4;
        tmp = "";
        while(s[i] != ' ') {
            tmp += s[i];
            i++;
        }        
        int number1 = stoi(tmp);
        tmp = "";
        i++;
        while(s[i] != ' '  && s[i] != '\0')  {
            tmp += s[i];
            i++;
        }        
        int number2 = stoi(tmp);
        tp = make_tuple("inc", number1, number2);
    }
    else {
        int i = 5;
        tmp = "";
        while(s[i] != ' ' && s[i] != '\0') {
            tmp += s[i];
            i++;
        }        
        int number = stoi(tmp);
        tp = make_tuple("push", number, 0);
    }
    // cout << get<0>(tp) << " " << get<1>(tp) << " " << get<2>(tp) << endl;
    return tp;
}

void push(vector<int> &v, int x) {
    v.push_back(x);
}
void pop(vector<int> &v) {
    v.pop_back();
}
void inc(vector<int> &v, int x, int y) {
    for(int i =0; i < x; i ++) {
        v[i] += y;
    }
}
void show(vector<int> v) {
    int n = v.size();
    if(n == 0) {
        cout << "EMPTY" <<endl;;
    }else {
        cout << v[n-1] << endl;
        // for(int i =0; i < n; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }
}
void superStack(vector<string> operations, int n) {
    vector<int> v;
    tuple<string, int, int> tp;
    for(string str : operations) {
        tp = extract(str);
        if(get<0>(tp) == "pop") {
            pop(v);
            show(v);
        }
        else if(get<0>(tp) == "inc") {
            inc(v, get<1>(tp), get<2>(tp));
            show(v);
        }
        else {
            push(v, get<1> (tp));
            show(v);
        }
    }
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file!";
        return 0;
    }
    vector<string> operations;
    int n;
    inputFile >> n;
    inputFile.ignore();
    for(int i =0; i < n; i++) {
        string s;
        getline(inputFile, s);
        operations.push_back(s);
    }
    superStack(operations, n);
    return 0;
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}