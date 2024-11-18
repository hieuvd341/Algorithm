#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    map<int, int> mp;
    int tmp;
    for(int i =0; i < n; i++){
        cin >> tmp;
        if(mp[tmp] > 0) {
            cout << "1" << endl;
        } else {
            cout << '0' << endl;
        }
        mp[tmp]++;
    }

}