#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;

void computeLPSArray( string pat, int M, int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < M) {
        if(pat[i] == pat[len] || pat[i] == '*' || pat[len] == '*') {
            len ++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0){
                len = lps[len -1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat,  string txt) {
    int M = pat.size();
    int N = txt.size();
    int *lps;
    bool flag = false;
    lps = (int *)malloc(M*sizeof(int));
    computeLPSArray(pat, M, lps);
    int i =0; 
    int j = 0;
    while((N-i) >= (M-j)) {
        if(pat[j] == txt[i] || pat[j] == '*') {
            j++;
            i++;
        }
        if(j == M) {
            flag = true;
            printf("Found pattern at index %d \n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && (pat[j] != txt[i] && pat[j] != '*')) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if(flag == false) {
        cout << "D thay dau ca"<< endl;
    }
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    string s;
    string x;
    inputFile >> s;
    inputFile >> x;
    KMPSearch(x,s);
}